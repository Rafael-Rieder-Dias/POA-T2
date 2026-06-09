#include "Funcoes.hpp"
#include <string>
#include <iostream>

/*void posicionaBigodudos(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(aux.add_b(x,y)){
                if(estados_visitados.insert(aux).second){
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
                if(estados_visitados.insert(aux).second){
                    if(aux.capetas_prontos()){
                        if(aux.cada_bigodudo_ve_dois_capetas()){
                            solucoes++;
                            cout << aux.toString() << endl;
                        }
                    }else posicionaCapetas(aux);
                }
                aux = pb;
            }
        }
    }
}*/

void recursao(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.size(); x++){
        for(int y = 0; y < pb.size(); y++){
            if(!aux.bigodudos_prontos()){
                if(aux.add(x,y,'b')){
                    if(estados_visitados.insert(aux).second){
                        if(!(aux.bigodudos_prontos() && aux.capetas_prontos())){
                            recursao(aux);
                        }else {solucoes++; /*solucoes_set.insert(aux);*/}
                    }
                    aux = pb;
                }
            }
            if(!aux.capetas_prontos()){
                if(aux.add(x,y,'c')){
                    if(estados_visitados.insert(aux).second){
                        if(!(aux.bigodudos_prontos() && aux.capetas_prontos())){
                            recursao(aux);
                        }else {solucoes++; /*solucoes_set.insert(aux);*/}
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