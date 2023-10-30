#include "MetodosInnatos.cpp"

//METODOS HUMANOS
void Humano::agregarAmigos(Humano * arrayDeLaVida[], int cantHumanosActual){
    Humano * candidatoAmigo=NULL;
    for (int i=0; i < cantHumanosActual; i++){
        candidatoAmigo=arrayDeLaVida[i];
        if (cantidadAmigos==0){
            break;
        }else if (candidatoAmigo->ID!=ID && candidatoAmigo->pais==pais && 
        (candidatoAmigo->creencia==creencia || candidatoAmigo->apellido==apellido || candidatoAmigo->profesion==profesion)){
            amigos->insertarFinal(candidatoAmigo);
            cantidadAmigos--;
        }
    }
}


void ArbolDeLaVida::generarAmigosYPecados(){
    Humano * humano=NULL;
    for (int i=0; i < cantidadHumanos; i++){
        humano=arrayDeLaVida[i];
        humano->agregarAmigos(arrayDeLaVida, cantidadHumanos);
    }
}

void Humano::inicializarPecados(){

}

void Humano::agregarPecado(){

}

//METODOS DE LA VIDA
bool ArbolDeLaVida::validarID(int ID){
    for(int i; i<cantidadHumanos;i++){
        if (arrayDeLaVida[i]->ID==ID){
            return false;
        }
    }
    return true;
}

