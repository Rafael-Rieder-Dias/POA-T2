#ifndef FUNCOES_HPP
#define FUNCOES_HPP
#include "PisoBar.hpp"
#include <unordered_set>
#include <mutex>
#include <vector>
#include <list>

using namespace std;

extern unsigned long long solucoes;
extern unordered_set<PisoBar, PisoBar::PisoBarHash> estados_visitados;
extern list<PisoBar> nivel1_1;
extern list<PisoBar> nivel1_2;
extern mutex mx_set;
extern mutex mx_vecs_big;
extern mutex mx_sol;
extern vector<PisoBar> bigodudos1;
extern vector<PisoBar> bigodudos2;
extern vector<PisoBar> bigodudos3;

bool insert(PisoBar pb);
void insertNivel1(PisoBar pb);
void insertListaBigMT(PisoBar pb);
void posicionaBigodudosMT(PisoBar pb);
void nivel1(PisoBar pb);
void posicionaCapetasMT(PisoBar pb);
void incCount();

#endif