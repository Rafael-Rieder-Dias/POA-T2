#include <iostream>
#include <chrono>
#include "PisoBar.hpp"
#include "Funcoes.hpp"
#include <unordered_set>

using namespace std;
using namespace chrono;

unsigned long long solucoes = 0;
unordered_set<PisoBar, PisoBar::PisoBarHash> estados_visitados = unordered_set<PisoBar, PisoBar::PisoBarHash>();

int ni,bi,ci,nf,bf,cf;

int main(int argc, char* argv[]){
    if(argc != 7){
        cout << "Numero de argumentos invalido." << endl;
        exit(0);
    }

    ni = stoi(argv[1]);
    bi = stoi(argv[2]);
    ci = stoi(argv[3]);
    nf = stoi(argv[4]);
    bf = stoi(argv[5]);
    cf = stoi(argv[6]);

    if(ni > nf || bi > bf || ci > cf){
        cout << "Os valores iniciais devem ser menores que os finais." << endl;
        exit(0);
    }

    if(bi < 2 || ci < 2){
        cout << "Cada quadrilha deve ter pelo menos 2 pistoleiros." << endl;
        exit(0);
    }

    auto inicio = steady_clock::now();
    auto fim = steady_clock::now();

    for(int n = ni; n < nf; n++){
        for(int b = bi; b < bf; b++){
            for(int c = ci; c < cf; c++){
                if(b > n || c > n) continue;
                inicio = steady_clock::now();
                posicionaBigodudos(PisoBar(n,b,c));
                fim = steady_clock::now();
                cout << n << " " << b << " " << c << " " << duration_cast<milliseconds>(fim-inicio).count() << " ms" << endl;
                estados_visitados.clear();
            }
        }
    }
}