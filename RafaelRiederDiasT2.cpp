#include <iostream>
#include "PisoBar.hpp"
#include "Funcoes.hpp"

int n = 0; int b = 0; int c = 0;
unsigned long long solucoes = 0;
unordered_set<PisoBar, PisoBar::PisoBarHash> estados_visitados = unordered_set<PisoBar, PisoBar::PisoBarHash>();
//unordered_set<PisoBar, PisoBar::PisoBarHash> solucoes_set = unordered_set<PisoBar, PisoBar::PisoBarHash>();

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

    if(b + c > n*n){
        cout << "O numero total de pistoleiros deve ser menor que n²." << endl;
        exit(0);
    }

    recursao(PisoBar(n,b,c));

    cout << solucoes << endl;

    /*PisoBar::PisoBarHash hash;
    set<size_t> hashs;*/
    /*for(PisoBar pb: solucoes_set){
        cout << pb.toString() << endl;
        //hashs.insert(hash.operator()(pb));
    }*/

    //cout << hashs.size() << endl;
}