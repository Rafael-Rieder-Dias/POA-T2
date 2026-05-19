#include <iostream>
#include <chrono>
#include <vector>
#include "PisoBar.hpp"
#include "Funcoes.hpp"

using namespace std;
using namespace chrono;

unsigned long long solucoes = 0;

struct Caso{
    int n, b, c;
    int64_t tempo;
    Caso(){
        n=b=c=0;
        tempo = 0;
    }
    Caso(int n_, int b_, int c_, int64_t t){
        n = n_; b = b_; c = c_;
        tempo = t;
    }
};

vector<Caso> casos;

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

    casos.reserve((nf-ni)*(bf-bi)*(cf-ci));

    for(int n = ni; n < nf; n++){
        for(int b = bi; b < bf; b++){
            for(int c = ci; c < cf; c++){
                if(b > n || c > n) continue;
                inicio = steady_clock::now();
                posicionaBigodudos(PisoBar(n,b,c));
                fim = steady_clock::now();
                casos.push_back(Caso(n,b,c,duration_cast<milliseconds>(fim-inicio).count()));
            }
        }
    }

    auto duracao = duration_cast<milliseconds>(fim-inicio);
    
    cout << duracao.count() << " ms" << endl;
}