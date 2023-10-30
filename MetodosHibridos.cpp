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
            if(!amigos->tieneAmigo(candidatoAmigo->ID)){
                amigos->insertarFinal(candidatoAmigo);
                cantidadAmigos--;
            }
        }
    }
}


void ArbolDeLaVida::generarAmigosYPecados(){
    Humano * humano=NULL;
    for (int i=0; i < cantidadHumanos; i++){
        humano=arrayDeLaVida[i];
        humano->agregarAmigos(arrayDeLaVida, cantidadHumanos);
        humano->inicializarPecados();
    }
}

void ArbolDeLaVida::crearGeneracionHumanos(int cantidadAGenerar){
    if (cantidadHumanos+cantidadAGenerar<=1000){
        int ID;
        string nombre, apellido, profesion, creencia, pais, nacimiento;
        for (int i = cantidadHumanos+1; i < cantidadAGenerar+cantidadHumanos; i++){
            nombre=extraerLineaAleatoria("nombres.txt",1000);
            apellido=extraerLineaAleatoria("apellido.txt",30);
            profesion=extraerLineaAleatoria("profesiones.txt",30);
            creencia=extraerLineaAleatoria("creencias.txt",30);
            pais=extraerLineaAleatoria("paises.txt",30);
            //nacimiento=generarFechaYHoraActual();
            do{
                ID=generarNumerosAleatorios(99999);
            } while (validarID(ID));
            
            
            arrayDeLaVida[i]= new Humano(ID,nombre,apellido,pais,creencia,profesion,nacimiento,generarNumerosAleatorios(100));
        }
    }
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

