#include "MetodosInnatos.cpp"

void Humano::agregarAmigos(Humano arrayDeLaVida[], int cantHumanosActual){
    Humano * candidatoAmigo=NULL;
    for (int i=0; i < cantHumanosActual; i++){
        candidatoAmigo=&arrayDeLaVida[i];
        if (cantidadAmigos==0){
            break;
        }else if (candidatoAmigo->ID!=ID && candidatoAmigo->pais==pais && 
        (candidatoAmigo->creencia==creencia || candidatoAmigo->apellido==apellido || candidatoAmigo->profesion==profesion)){
            amigos->insertarFinal(candidatoAmigo);
            cantidadAmigos--;
        }
    }
}

void generarAmigosYPecados(Humano arrayDeLaVida[], int cantHumanosActual){
    Humano * humano=NULL;
    for (int i=0; i < cantHumanosActual; i++){
        humano=&arrayDeLaVida[i];
        humano->agregarAmigos(arrayDeLaVida, cantHumanosActual);
        
    }
}

void Humano::inicializarPecados(){

}

void Humano::agregarPecado(){

}