#include "Funcoes.hpp"

void recursao(PisoBar pb){
    PisoBar aux = pb;

    if(aux.bigodudos_prontos() && !aux.capetas_prontos()){
        if(aux.c__atual() >= 2){
            if(!aux.cada_capeta_ve_dois_bigodudos()){
                return;
            }
        }
    }

    if(aux.capetas_prontos() && !aux.bigodudos_prontos()){
        if(aux.b__atual() >= 2){
            if(!aux.cada_bigodudo_ve_dois_capetas()){
                return;
            }
        }
    }

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(!aux.bigodudos_prontos()){
                if(aux.add(x,y,'b')){
                    if(estados_visitados.insert(aux).second){
                        if(!(aux.bigodudos_prontos() && aux.capetas_prontos())){
                            recursao(aux);
                        }else{
                            if(aux.cada_bigodudo_ve_dois_capetas() && aux.cada_capeta_ve_dois_bigodudos()) {solucoes++;}
                        }
                    }
                    aux = pb;
                }
            }
            if(!aux.capetas_prontos()){
                if(aux.add(x,y,'c')){
                    if(estados_visitados.insert(aux).second){
                        if(!(aux.bigodudos_prontos() && aux.capetas_prontos())){
                            recursao(aux);
                        }else{
                            if(aux.cada_bigodudo_ve_dois_capetas() && aux.cada_capeta_ve_dois_bigodudos()) {solucoes++;}
                        }
                    }
                    aux = pb;
                }
            }
            if(aux.bigodudos_prontos() && aux.capetas_prontos()){
                return;
            }
        }
    }
}