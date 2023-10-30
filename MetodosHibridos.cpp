#include "MetodosInnatos.cpp"

void Humano::agregarAmigos(Humano arrayDeLaVida[], int cantHumanosActual){
    Humano * candidatoAmigo=NULL;
    for (int i=0; i < cantHumanosActual; i++){
        candidatoAmigo=&arrayDeLaVida[i];
        if (cantidadAmigos==0){
            break;
        }else if (candidatoAmigo->ID!=ID && candidatoAmigo->pais==pais && 
        (candidatoAmigo->creencia==creencia || candidatoAmigo->apellido==apellido || candidatoAmigo->profesion==profesion)){
            if(!amigos->tieneAmigo(candidatoAmigo->ID)){
                amigos->insertarFinal(candidatoAmigo);
                cantidadAmigos--;
            }
        }
    }
}

void generarAmigosYPecados(Humano arrayDeLaVida[], int cantHumanosActual){
    Humano * humano=NULL;
    for (int i=0; i < cantHumanosActual; i++){
        humano=&arrayDeLaVida[i];
        humano->agregarAmigos(arrayDeLaVida, cantHumanosActual);
        humano->inicializarPecados();
    }
}

int crearGeneracionHumanos(int cantidad, Humano arrayDeLaVida[], int cantHumanosActual){
    if (cantHumanosActual+cantidad>1000){
        return 1001;
    }
    int ID;
    string nombre, apellido, profesion, creencia, pais, nacimiento;
    for (int i = cantHumanosActual+1; i < cantidad+cantHumanosActual; i++){
        nombre=extraerLineaAleatoria("nombres.txt",1000);
        apellido=extraerLineaAleatoria("apellido.txt",30);
        profesion=extraerLineaAleatoria("profesiones.txt",30);
        creencia=extraerLineaAleatoria("creencias.txt",30);
        pais=extraerLineaAleatoria("paises.txt",30);
        //nacimiento=generarFechaYHoraActual();
        do{
            ID=generarNumerosAleatorios(99999);
        } while (validarID(ID));
        
        
        arrayDeLaVida[i]=* new Humano(ID,nombre,apellido,pais,creencia,profesion,nacimiento,generarNumerosAleatorios(100));
    }
    return cantHumanosActual;
}

