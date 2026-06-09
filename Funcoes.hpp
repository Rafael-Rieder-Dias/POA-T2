#ifndef FUNCOES_HPP
#define FUNCOES_HPP
#include "PisoBar.hpp"
#include <unordered_set>

using namespace std;

extern unsigned long long solucoes;
extern unordered_set<PisoBar, PisoBar::PisoBarHash> estados_visitados;
//extern unordered_set<PisoBar, PisoBar::PisoBarHash> solucoes_set;

//void posicionaBigodudos(PisoBar pb);
//void posicionaCapetas(PisoBar pb);
void recursao(PisoBar pb);

#endif