#include "Funcoes.hpp"

void posicionaBigodudos(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(aux.add_b(x,y)){
                if(!estados_visitados.contains(aux)){
                    estados_visitados.insert(aux);
                    if(aux.bigodudos_prontos()) posicionaCapetas(aux);
                    else posicionaBigodudos(aux);
                }
                aux = pb;
            }
        }
    }
}

void posicionaCapetas(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(aux.add_c(x,y)){
                if(!estados_visitados.contains(aux)){
                    estados_visitados.insert(aux);
                    if(aux.capetas_prontos()){
                        if(aux.cada_bigodudo_ve_dois_capetas()) solucoes++;
                    }else posicionaCapetas(aux);
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
                if(!estados_visitados.contains(aux)){
                    estados_visitados.insert(aux);
                    if(aux.bigodudos_prontos()) insertListaBigMT(aux);
                    else posicionaBigodudos(aux);
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
                if(!estados_visitados.contains(aux)){
                    insert(aux);
                    if(aux.capetas_prontos()){
                        if(aux.cada_bigodudo_ve_dois_capetas()) solucoes++;
                    }else posicionaCapetas(aux);
                }
                aux = pb;
            }
        }
    }
}

bool jaVisitou(PisoBar aux){
    mx.lock();
    return estados_visitados.contains(aux);
}

void insert(PisoBar aux){
    mx.lock();
    estados_visitados.insert(aux);
    mx.unlock();
}

void insertListaBigMT(PisoBar pb){
    if((bigodudos1.size() + bigodudos2.size())%2 == 0){
        bigodudos1.push_back(pb);
    }else{
        bigodudos2.push_back(pb);
    }
}