#include "Funcoes.hpp"

void nivel1(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(aux.add_b(x,y)){
                if(!estados_visitados.contains(aux)){
                    estados_visitados.insert(aux);
                    insertNivel1(aux);
                }
                aux = pb;
            }
        }
    }
}

void posicionaBigodudosMT(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(aux.add_b(x,y)){
                if(insert(aux)){
                    
                    if(aux.bigodudos_prontos()) insertListaBigMT(aux);
                    else posicionaBigodudosMT(aux);
                }
                aux = pb;
            }
        }
    }
}

void posicionaCapetasMT(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(aux.add_c(x,y)){
                if(insert(aux)){
                    
                    if(aux.capetas_prontos()){
                        if(aux.cada_bigodudo_ve_dois_capetas()) incCount();
                    }else posicionaCapetasMT(aux);
                }
                aux = pb;
            }
        }
    }
}

bool insert(PisoBar aux){
    lock_guard<mutex> lock(mx_set);
    if(estados_visitados.contains(aux)) return false;
    estados_visitados.insert(aux);
    return true;
}

void insertNivel1(PisoBar pb){
    if((nivel1_1.size() + nivel1_2.size())%2 == 0){
        nivel1_1.push_back(pb);
    }else{
        nivel1_2.push_back(pb);
    }
}

void insertListaBigMT(PisoBar pb){
    lock_guard<mutex> lock(mx_vecs_big);
    switch((bigodudos1.size() + bigodudos2.size() + bigodudos3.size())%3){
        case 0: bigodudos1.push_back(pb); break;
        case 1: bigodudos2.push_back(pb); break;
        case 2: bigodudos3.push_back(pb); break;
    }
}

void incCount(){
    lock_guard<mutex> lock(mx_sol);
    solucoes++;
}