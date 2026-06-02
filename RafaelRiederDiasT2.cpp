#include <iostream>
#include "Funcoes.hpp"
#include <thread>

using namespace std;

int n = 0; int b = 0; int c = 0;
unsigned long long solucoes = 0;
unordered_set<PisoBar, PisoBar::PisoBarHash> estados_visitados = unordered_set<PisoBar, PisoBar::PisoBarHash>();
list<PisoBar> nivel1_1;
list<PisoBar> nivel1_2;
mutex mx = mutex();
vector<PisoBar> bigodudos1;
vector<PisoBar> bigodudos2;

/**
 * [...] os pistoleiros podiam se “enxergar” como se fossem rainhas do jogo de xadrez, olhando
 * apenas a mesma linha, coluna e as diagonais.
 * 
 * [...] apenas dos casos em que um pistoleiro só vê pelo menos dois pistoleiros da outra
 * quadrilha e nenhum da sua. São pelo menos dois dos outros pra poder apontar uma arma
 * para cada um, igual nos filmes.
 */

void f1(){
    for(PisoBar pb: nivel1_1){
        posicionaBigodudosMT(pb);
    }
    cout << "f1" << endl;
}

void f2(){
    for(PisoBar pb: nivel1_2){
        posicionaBigodudosMT(pb);
    }
    cout << "f2" << endl;
}

void f3(){
    for(PisoBar pb: bigodudos1){
        posicionaCapetasMT(pb);
    }
    cout << "f3" << endl;
}

void f4(){
    for(PisoBar pb: bigodudos2){
        posicionaCapetasMT(pb);
    }
    cout << "f4" << endl;
}

void aux(){
    thread t3(f3);
    thread t4(f4);

    t3.join();
    t4.join();

    cout << "Capetas posicionados." << endl;

    cout << "Numero de solucoes: " << solucoes << endl;
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
    bigodudos1.reserve(10000);
    bigodudos2.reserve(10000);
    nivel1_1 = list<PisoBar>();
    nivel1_2 = list<PisoBar>();

    nivel1(PisoBar(n,b,c));
    cout << "nivel 1" << endl;

    thread t1(f1);
    thread t2(f2);

    t1.join();
    t2.join();

    cout << "Bigodudos posicionados." << endl;
    aux();
}