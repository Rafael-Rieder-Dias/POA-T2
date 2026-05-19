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
        //função auxiliar privada
        bool priv_cada_bigodudo_ve_dois_capetas(unsigned int x, unsigned int y);

    public:
        PisoBar(unsigned int n_, unsigned int b_, unsigned int c_);
        PisoBar();
        //retorna dimensão do bar
        unsigned int get_n();
        //retorna se todos os bigodudos já foram posicionados
        bool bigodudos_prontos();
        //retorna se todos os capetas já foram posicionados
        bool capetas_prontos();
        //adiciona um bigodudo (ainda não há capetas para saber se o bigodudo conseguirá ver 2)
        bool add_b(unsigned int x, unsigned int y);
        //adiciona um capeta (verificar que desta posição dá para ver pelo menos 2 bigodudos)
        bool add_c(unsigned int x, unsigned int y);
        //verifica se todos os bigodudos conseguem ver pelo menos 2 capetas
        bool cada_bigodudo_ve_dois_capetas();
        PisoBar clone();
        void desalocaMatriz();

};