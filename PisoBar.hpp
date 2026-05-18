#define PISOBAR_HPP

const char bigodudos = 'b';
const char capetas = 'c';

char** alocaMatriz(unsigned int n);

class PisoBar{
    private:
        //n é a dimensão do piso
        unsigned int n;
        //b é o limite de bigodudos
        unsigned int b;
        //c é o limite de capetas
        unsigned int c;
        //b_atual é a quantidade atual de bigodudos
        unsigned int b_atual;
        //c_atual é a quantidade atual de capetas
        unsigned int c_atual;
        //matriz de posições dos pistoleiros
        char** matriz;

    public:
        PisoBar(unsigned int n_, unsigned int b_, unsigned int c_);
        PisoBar();
        unsigned int get_b();
        unsigned int get_c();
        unsigned int get_b_atual();
        unsigned int get_c_atual();
        bool add(unsigned int x, unsigned int y, char quadrilha);
        bool pronto();
};