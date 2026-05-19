#include "PisoBar.hpp"

char** alocaMatriz(unsigned int n){
    char** m = new char*[n];
    for(unsigned int i = 0; i < n; i++){
        m[i] = new char[n];
    }
    return m;
}

PisoBar::PisoBar(unsigned int n_, unsigned int b_, unsigned int c_){
    this->n = n_;
    this->b = b_;
    this->c = c_;
    this->b_atual = 0;
    this->c_atual = 0;
    this->matriz = alocaMatriz(n_);
}

PisoBar::PisoBar(){
    this->n = 0;
    this->b = 0;
    this->c = 0;
    this->b_atual = 0;
    this->c_atual = 0;
    this->matriz = nullptr;
}

unsigned int PisoBar::get_n(){return this->n;}

bool PisoBar::bigodudos_prontos(){return this->b_atual == this->b;}
bool PisoBar::capetas_prontos(){return this->c_atual == this->c;}

bool PisoBar::add_b(unsigned int x, unsigned int y){
    if(this->b_atual == this->b) return false;

    if(x >= this->n || y >= this->n) return false;

    if(this->matriz[x][y] != 0) return false;

    for(unsigned int i = 0; i < this->n; i++){
        if(this->matriz[x][i] == bigodudos) return false;
        if(this->matriz[i][y] == bigodudos) return false;
    }

    //diagonal superior esquerda
    int i = x - 1;
    int j = y - 1;
    while(i >= 0 && j >= 0){
        if(this->matriz[i][j] == bigodudos) return false;
        i--;
        j--;
    }

    //diagonal superior direita
    i = x - 1;
    j = y + 1;
    while(i >= 0 && j < this->n){
        if(this->matriz[i][j] == bigodudos) return false;
        i--;
        j++;
    }

    //diagonal inferior esquerda
    i = x + 1;
    j = y - 1;
    while(i < this->n && j >= 0){
        if(this->matriz[i][j] == bigodudos) return false;
        i++;
        j--;
    }

    i = x + 1;
    j = y + 1;
    while(i < this->n && j < this->n){
        if(this->matriz[i][j] == bigodudos) return false;
        i++;
        j++;
    }

    this->matriz[x][y] = bigodudos;
    this->b_atual++;
    return true;
}

bool PisoBar::add_c(unsigned int x, unsigned int y){
    if(this->c_atual == this->c) return false;

    if(x >= this->n || y >= this->n) return false;

    if(this->matriz[x][y] != 0) return false;

    unsigned int bigodudos_em_vista = 0;

    for(unsigned int i = 0; i < this->n; i++){
        if(this->matriz[x][i] == capetas){
            return false;
        }else if(this->matriz[x][i] == bigodudos) bigodudos_em_vista++;
        

        if(this->matriz[i][y] == capetas){
            return false;
        }else if(this->matriz[x][i] == bigodudos) bigodudos_em_vista++;
        
    }

    //diagonal superior esquerda
    int i = x - 1;
    int j = y - 1;
    while(i >= 0 && j >= 0){
        if(this->matriz[i][j] == capetas){
            return false;
        }else if(this->matriz[i][j] == bigodudos) bigodudos_em_vista++;
        
        i--;
        j--;
    }

    //diagonal superior direita
    i = x - 1;
    j = y + 1;
    while(i >= 0 && j < this->n){
        if(this->matriz[i][j] == capetas){
            return false;
        }else if(this->matriz[i][j] == bigodudos) bigodudos_em_vista++;
        
        i--;
        j++;
    }

    //diagonal inferior esquerda
    i = x + 1;
    j = y - 1;
    while(i < this->n && j >= 0){
        if(this->matriz[i][j] == capetas){
            return false;
        }else if(this->matriz[i][j] == bigodudos) bigodudos_em_vista++;
        
        i++;
        j--;
    }

    i = x + 1;
    j = y + 1;
    while(i < this->n && j < this->n){
        if(this->matriz[i][j] == capetas){
            return false;
        }else if(this->matriz[i][j] == bigodudos) bigodudos_em_vista++;
        
        i++;
        j++;
    }

    if(bigodudos_em_vista < 2) return false;
    this->matriz[x][y] = capetas;
    this->c_atual++;
    return true;
}

bool PisoBar::cada_bigodudo_ve_dois_capetas(){
    for(unsigned int x = 0; x < this->n; x++){
        for(unsigned int y = 0; y < this->n; y++){
            if(this->matriz[x][y] == bigodudos){
                if(!this->priv_bigodudo_ve_dois_capetas(x,y)) return false;
            }
        }
    }
    return true;
}

bool PisoBar::priv_bigodudo_ve_dois_capetas(unsigned int x, unsigned int y){
    unsigned int capetas_em_vista = 0;

    for(unsigned int i = 0; i < this->n; i++){
        if(this->matriz[x][i] == capetas) capetas_em_vista++;
        if(this->matriz[i][y] == capetas) capetas_em_vista++;
    }

    if(capetas_em_vista >= 2) return true;

    //diagonal superior esquerda
    int i = x - 1;
    int j = y - 1;
    while(i >= 0 && j >= 0){
        if(this->matriz[i][j] == capetas) capetas_em_vista++;
        i--;
        j--;
    }

    //diagonal superior direita
    i = x - 1;
    j = y + 1;
    while(i >= 0 && j < this->n){
        if(this->matriz[i][j] == capetas) capetas_em_vista++;
        i--;
        j++;
    }

    if(capetas_em_vista >= 2) return true;

    //diagonal inferior esquerda
    i = x + 1;
    j = y - 1;
    while(i < this->n && j >= 0){
        if(this->matriz[i][j] == capetas) capetas_em_vista++;
        i++;
        j--;
    }

    i = x + 1;
    j = y + 1;
    while(i < this->n && j < this->n){
        if(this->matriz[i][j] == capetas) capetas_em_vista++;
        i++;
        j++;
    }

    if(capetas_em_vista < 2) return false;
    return true;    
}

PisoBar PisoBar::clone(){
    PisoBar clone = PisoBar();
    clone.n = this->n;
    clone.b = this->b;
    clone.c = this->c;
    clone.b_atual = this->b_atual;
    clone.c_atual = this->c_atual;
    clone.matriz = alocaMatriz(this->n);
    for(int x = 0; x < this->n; x++){
        for(int y = 0; y < this->n; y++){
            clone.matriz[x][y] = this->matriz[x][y];
        }
    }
    return clone;
}

void PisoBar::desalocaMatriz(){
    for(int i = 0; i < this->n; i++){
        delete [] matriz[i];
    }
    delete [] matriz;
}