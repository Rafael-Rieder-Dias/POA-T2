#include "Funcoes.hpp"

void posicionaBigodudos(PisoBar pb){
    PisoBar aux = pb.clone();

    for(int x = 0; x < pb.get_n(); x++){
        for(int y = 0; y < pb.get_n(); y++){
            if(aux.add_b(x,y)){
                if(aux.bigodudos_prontos()) posicionaCapetas(aux);
                else posicionaBigodudos(aux);

                aux.desalocaMatriz();
                aux = pb.clone();
            }
        }
    }
    aux.desalocaMatriz();
}

void posicionaCapetas(PisoBar pb){
    PisoBar aux = pb.clone();

    for(int x = 0; x < pb.get_n(); x++){
        for(int y = 0; y < pb.get_n(); y++){
            if(aux.add_c(x,y)){
                if(aux.capetas_prontos()){
                    if(aux.cada_bigodudo_ve_dois_capetas()) solucoes++;
                }else posicionaCapetas(aux);

                aux.desalocaMatriz();
                aux = pb.clone();
            }
        }
    }
    aux.desalocaMatriz();
}