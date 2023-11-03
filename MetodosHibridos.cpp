#include "MetodosInnatos.cpp"

//METODOS HUMANOS -------------------------------------------------------------------------------------
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

//METODOS DE LA VIDA ----------------------------------------------------------------------------------
void ArbolDeLaVida::generarAmigosYPecados(){
    for (int i=0; i < cantidadHumanos; i++){
        arrayDeLaVida[i]->agregarAmigos(arrayDeLaVida, cantidadHumanos);
        arrayDeLaVida[i]->inicializarPecados();
        arrayDeLaVida[i]->inicializarRedesSociales();
    }
}

//MENUS -------------------------------------------------------------------------------------------------
void ArbolDeLaVida::enviarAPecar(int ID, string redSocial, string pecado){
    for (int i=0; i < cantidadHumanos; i++){
        if(arrayDeLaVida[i]->ID==ID){
            arrayDeLaVida[i]->publicarEnRedSocial(redSocial, pecado);
        }
    }
}

void menuPublicarPorHumano(ArbolDeLaVida * arbol){
    string ID;
    int redSocial;
	cout<<"Ingrese el ID del Humano: "<<endl;
    getline(cin,ID);
    redSocial=seleccionarRedSocial();
    string pecadosCapitales[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    string nombresRedes[]={"Tinder", "iFood", "LinkedIn", "Netflix", "Twitter", "Facebook", "Instagram"};
    arbol->enviarAPecar(stoi(ID),nombresRedes[redSocial-1],pecadosCapitales[redSocial-1]);
}

void menuPublicarPorReligion(ArbolDeLaVida * arbol){
    for (int i = 0; i < arbol->cantidadHumanos; i++){
        
    } 
}

void menuPublicarRedesSociales(ArbolDeLaVida *arbol){
    string opcion;
    do{
        cout<<"------------------------------- OPCIONES -------------------------------"<<endl;
	    cout<<"1: Por Humano"<<endl;
	    cout<<"2: Por Religión"<<endl;
	    cout<<"3: Por Profesión"<<endl;
	    cout<<"4: Por Familia"<<endl;
	    getline(cin,opcion);
    } while (!esInt(opcion)); //validaciones 
    switch (stoi(opcion)){
    case 1:
        menuPublicarPorHumano(arbol);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
	    cout<<"La opción seleccionada no existe"<<endl;
        break;
    }
}


