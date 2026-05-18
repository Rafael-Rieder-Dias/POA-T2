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
}