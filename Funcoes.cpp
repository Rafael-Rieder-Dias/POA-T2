#include "Funcoes.hpp"

void posicionaBigodudos(PisoBar pb){
    PisoBar aux = pb;

    for(int x = 0; x < pb.get_n(); x++){
        for(int y = 0; y < pb.get_n(); y++){
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

    for(int x = 0; x < pb.get_n(); x++){
        for(int y = 0; y < pb.get_n(); y++){
            if(aux.add_c(x,y)){
                if(!estados_visitados.contains(aux)){
                    estados_visitados.insert(aux);
                    if(aux.capetas_prontos() && aux.cada_bigodudo_ve_dois_capetas()) solucoes++;
                    else posicionaCapetas(aux);
                }

                aux = pb;
            }
        }
    }
}