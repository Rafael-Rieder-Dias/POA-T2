#include "PisoBar.hpp"
#include <functional>

char** alocaMatriz(int n){
    char** m = new char*[n];
    for(int i = 0; i < n; i++){
        m[i] = new char[n];
    }
    return m;
}

PisoBar::PisoBar(int n_, int b_, int c_){
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

PisoBar::PisoBar(const PisoBar& other){
    this->n = other.n;
    this->b = other.b;
    this->c = other.c;
    this->b_atual = other.b_atual;
    this->c_atual = other.c_atual;

    this->matriz = alocaMatriz(this->n);

    for(int x = 0; x < this->n; x++){
        for(int y = 0; y < this->n; y++){
            this->matriz[x][y] = other.matriz[x][y];
        }
    }
}

PisoBar::~PisoBar(){
    this->desalocaMatriz();
}

int PisoBar::size(){return this->n;}

bool PisoBar::bigodudos_prontos(){return this->b_atual == this->b;}
bool PisoBar::capetas_prontos(){return this->c_atual == this->c;}

bool PisoBar::add(int x, int y, char p){
    if(matriz[x][y] != 0) return false;
    if(x >= this->n || y >= this->n) return false;

    int x_ = x-1;
    int y_;
    char not_p;
    if(p == bigodudos){
        if(b_atual >= b) return false;
        not_p = capetas;
    }else{
        if(c_atual >= c) return false;
        not_p = bigodudos;
    }

    //parte esquerda da linha
    while(x_ >= 0){
        if(matriz[x_][y] == p) return false;
        if(matriz[x_][y] == not_p) break;
        x_--;
    }

    //parte direita da linha
    x_ = x+1;
    while(x_ < n){
        if(matriz[x_][y] == p) return false;
        if(matriz[x_][y] == not_p) break;
        x_++;
    }

    //parte de cima da coluna
    y_ = y-1;
    while(y_ >= 0){
        if(matriz[x][y_] == p) return false;
        if(matriz[x][y_] == not_p) break;
        y_--;
    }

    //parte de baixo da coluna
    y_ = y+1;
    while(y_ < n){
        if(matriz[x][y_] == p) return false;
        if(matriz[x][y_] == not_p) break;
        y_++;
    }

    //diagonais
    x_ = x-1;
    y_ = y-1;
    while(x_ >= 0 && y_ >= 0){
        if(matriz[x_][y_] == p) return false;
        if(matriz[x_][y_] == not_p) break;
        x_--;
        y_--;
    }

    x_ = x-1;
    y_ = y+1;
    while(x_ >= 0 && y_ < n){
        if(matriz[x_][y_] == p) return false;
        if(matriz[x_][y_] == not_p) break;
        x_--;
        y_++;
    }

    x_ = x+1;
    y_ = y-1;
    while(x_ < n && y_ >= 0){
        if(matriz[x_][y_] == p) return false;
        if(matriz[x_][y_] == not_p) break;
        x_++;
        y_--;
    }

    x_ = x+1;
    y_ = y+1;
    while(x_ < n && y_ < n){
        if(matriz[x_][y_] == p) return false;
        if(matriz[x_][y_] == not_p) break;
        x_++;
        y_++;
    }

    matriz[x][y] = p;
    if(p == bigodudos) b_atual++;
    else c_atual++;
    return true;
}

bool PisoBar::add_b(int x, int y){
    if(this->b_atual == this->b) return false;

    if(x >= this->n || y >= this->n) return false;

    if(this->matriz[x][y] != 0) return false;

    for(int i = 0; i < this->n; i++){
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

    //diagonal inferior direita
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

bool PisoBar::add_c(int x, int y){
    if(this->c_atual == this->c) return false;

    if(x >= this->n || y >= this->n) return false;

    if(this->matriz[x][y] != 0) return false;

    int bigodudos_em_vista = 0;

    for(int i = 0; i < this->n; i++){
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
    for(int x = 0; x < this->n; x++){
        for(int y = 0; y < this->n; y++){
            if(this->matriz[x][y] == bigodudos){
                if(!this->priv_bigodudo_ve_dois_capetas(x,y)) return false;
            }
        }
    }
    return true;
}

bool PisoBar::priv_bigodudo_ve_dois_capetas(int x, int y){
    int capetas_em_vista = 0;

    for(int i = 0; i < this->n; i++){
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

void PisoBar::desalocaMatriz(){
    for(int i = 0; i < this->n; i++){
        delete [] matriz[i];
    }
    delete [] matriz;
}

bool PisoBar::operator==(const PisoBar& other) const{
    if(this->n != other.n || this->b != other.b || this->c != other.c
        || this->b_atual != other.b_atual || this->c_atual != other.c_atual){
            return false;
    }

    for(int x = 0; x < this->n; x++){
        for(int y = 0; y < this->n; y++){
            if(this->matriz[x][y] != other.matriz[x][y]) return false;
        }
    }

    return true;
}

PisoBar& PisoBar::operator=(const PisoBar& other){
    if(this == &other) return *this;

    this->desalocaMatriz();

    this->n = other.n;
    this->b = other.b;
    this->c = other.c;
    this->b_atual = other.b_atual;
    this->c_atual = other.c_atual;

    this->matriz = alocaMatriz(this->n);

    for(int x = 0; x < this->n; x++){
        for(int y = 0; y < this->n; y++){
            this->matriz[x][y] = other.matriz[x][y];
        }
    }

    return *this;
}

size_t PisoBar::PisoBarHash::operator()(const PisoBar& pb) const {
    auto combine = [](size_t seed, size_t value) {
        return seed ^ (value + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2));
    };

    size_t h = 0;
    h = combine(h, std::hash<int>{}(pb.n));
    h = combine(h, std::hash<int>{}(pb.b));
    h = combine(h, std::hash<int>{}(pb.c));
    h = combine(h, std::hash<int>{}(pb.b_atual));
    h = combine(h, std::hash<int>{}(pb.c_atual));

    for (int x = 0; x < pb.n; ++x) {
        for (int y = 0; y < pb.n; ++y) {
            h = combine(h, std::hash<char>{}(pb.matriz[x][y]));
        }
    }

    return h;
}

string PisoBar::toString(){
    string s;
    s.reserve(n*n+3);

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(matriz[x][y] == 0){
                s += '0';
            }else{
                s += matriz[x][y];
            }
            if(x < n-1){
                s += ' ';
            }
        }
        s += '\n';
    }

    return s;
}