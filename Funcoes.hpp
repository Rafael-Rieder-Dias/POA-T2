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
extern mutex mx;
extern vector<PisoBar> bigodudos1;
extern vector<PisoBar> bigodudos2;

//bool jaVisitou(PisoBar pb);
void insert(PisoBar pb);
void insertNivel1(PisoBar pb);
void insertListaBigMT(PisoBar pb);
void posicionaBigodudosMT(PisoBar pb);
void nivel1(PisoBar pb);
void posicionaCapetasMT(PisoBar pb);
void incCount();

void posicionaBigodudos(PisoBar pb);
void posicionaCapetas(PisoBar pb);

#endif