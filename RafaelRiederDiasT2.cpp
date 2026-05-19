#include <iostream>
#include "PisoBar.hpp"

using namespace std;

unsigned int n = 0; unsigned int b = 0; unsigned int c = 0;
unsigned long long solucoes = 0;

/**
 * [...] os pistoleiros podiam se “enxergar” como se fossem rainhas do jogo de xadrez, olhando
 * apenas a mesma linha, coluna e as diagonais.
 * 
 * [...] apenas dos casos em que um pistoleiro só vê pelo menos dois pistoleiros da outra
 * quadrilha e nenhum da sua. São pelo menos dois dos outros pra poder apontar uma arma
 * para cada um, igual nos filmes.
 */
void posicionaCapetas(PisoBar pb);
void posicionaBigodudos(PisoBar pb){
    PisoBar aux = pb.clone();

    for(unsigned int x = 0; x < pb.get_n(); x++){
        for(unsigned int y = 0; y < pb.get_n(); y++){
            if(aux.add_b(x,y)){
                if(aux.bigodudos_prontos()) posicionaCapetas(aux);
                else posicionaBigodudos(aux);

                aux.desalocaMatriz();
                aux = pb.clone();
            }
        }
    }
    aux.desalocaMatriz();
}

void posicionaCapetas(PisoBar pb){
    PisoBar aux = pb.clone();

    for(unsigned int x = 0; x < pb.get_n(); x++){
        for(unsigned int y = 0; y < pb.get_n(); y++){
            if(aux.add_c(x,y)){
                if(aux.capetas_prontos()){
                    if(aux.cada_bigodudo_ve_dois_capetas()) solucoes++;
                }else posicionaCapetas(aux);

                aux.desalocaMatriz();
                aux = pb.clone();
            }
        }
    }
    aux.desalocaMatriz();
}

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Numero de argumentos invalido." << endl;
        exit(0);
    }

    n = stoi(argv[1]);
    b = stoi(argv[2]);
    c = stoi(argv[3]);

    if(b < 2 || c < 2){
        cout << "Cada quadrilha deve ter pelo menos 2 pistoleiros." << endl;
        exit(0);
    }

    if(b + c > n*n){
        cout << "O numero total de pistoleiros deve ser menor que n²." << endl;
        exit(0);
    }

    posicionaBigodudos(PisoBar(n,b,c));

    cout << "Numero de solucoes: " << solucoes << endl;
}