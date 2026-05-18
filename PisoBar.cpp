#include "PisoBar.hpp"

char** alocaMatriz(unsigned int n){
    char** m = new char*[n];
    for(int i = 0; i < n; i++){
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

unsigned int PisoBar::get_b(){return this->b;}

unsigned int PisoBar::get_c(){return this->c;}

unsigned int PisoBar::get_b_atual(){return this->b_atual;}

unsigned int PisoBar::get_c_atual(){return this->c_atual;}

bool PisoBar::add(unsigned int x, unsigned int y, char quadrilha){
    if(x >= this->n || y >= this->n || (quadrilha != bigodudos && quadrilha != capetas)) return false;

    if(this->matriz[x][y] != 0) return false;
}

bool PisoBar::pronto(){
    return this->b_atual == this->b && this->c_atual == this->c;
}