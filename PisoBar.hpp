#ifndef PISOBAR_HPP
#define PISOBAR_HPP
#include <cstddef>

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

    public:
        PisoBar(int n_, int b_, int c_);
        PisoBar();
        PisoBar(const PisoBar& other);
        ~PisoBar();
        //retorna dimensão do bar
        int get_n();
        //retorna se todos os bigodudos já foram posicionados
        bool bigodudos_prontos();
        //retorna se todos os capetas já foram posicionados
        bool capetas_prontos();
        //adiciona um bigodudo (ainda não há capetas para saber se o bigodudo conseguirá ver 2)
        bool add_b(int x, int y);
        //adiciona um capeta (verificar que desta posição dá para ver pelo menos 2 bigodudos)
        bool add_c(int x, int y);
        //verifica se todos os bigodudos conseguem ver pelo menos 2 capetas
        bool cada_bigodudo_ve_dois_capetas();
        PisoBar clone();
        void desalocaMatriz();
        bool operator==(const PisoBar& other) const;
        PisoBar& operator=(const PisoBar& other);

        struct PisoBarHash{
            size_t operator()(const PisoBar& pb) const;
        };

};

#endif