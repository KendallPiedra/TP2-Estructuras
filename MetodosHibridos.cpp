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

void menuPublicarPorHumano(){
    string ID;
    int redSocial;
	cout<<"Ingrese el ID del Humano: "<<endl;
    getline(cin,ID);
    redSocial=seleccionarRedSocial();
    // 1: Tinder
	// 2: iFood
	// 3: LinkedIn
	// 4: Netflix
	// 5: Twitter
	// 6: Facebook
	// 7: Instagram
    switch (redSocial){
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    default:
        break;
    }
}

void menuPublicarRedesSociales(){
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
        menuPublicarPorHumano();
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


