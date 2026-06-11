#ifndef PISOBAR_HPP
#define PISOBAR_HPP
#include <cstddef>

using namespace std;

const char bigodudos = 'b';
const char capetas = 'c';

char** alocaMatriz(int n);

class PisoBar{
    private:
        //n é a dimensão do piso
        int n;
        //b é o limite de bigodudos
        int b;
        //c é o limite de capetas
        int c;
        //b_atual é a quantidade atual de bigodudos
        int b_atual;
        //c_atual é a quantidade atual de capetas
        int c_atual;
        //matriz de posições dos pistoleiros
        char** matriz;
        //função auxiliar privada
        bool priv_bigodudo_ve_dois_capetas(int x, int y);
        //função auxiliar privada
        bool priv_capeta_ve_dois_bigodudos(int x, int y);
        void desalocaMatriz();

    public:
        PisoBar(int n_, int b_, int c_);
        PisoBar();
        PisoBar(const PisoBar& other);
        ~PisoBar();
        //retorna dimensão do bar
        int size();
        //quantidade atual de bigodudos
        int b__atual();
        //quantidade atual de capetas
        int c__atual();
        //retorna se todos os bigodudos já foram posicionados
        bool bigodudos_prontos();
        //retorna se todos os capetas já foram posicionados
        bool capetas_prontos();
        //adiciona um pistoleiro
        bool add(int x, int y, char p);
        //verifica se todos os bigodudos conseguem ver pelo menos 2 capetas
        bool cada_bigodudo_ve_dois_capetas();
        //verifica se todos os capetas conseguem ver pelo menos 2 bigodudos
        bool cada_capeta_ve_dois_bigodudos();
        bool operator==(const PisoBar& other) const;
        PisoBar& operator=(const PisoBar& other);

        struct PisoBarHash{
            size_t operator()(const PisoBar& pb) const;
        };
};

#endif