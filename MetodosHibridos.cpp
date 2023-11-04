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

//FAMILIAS
int Familia::determinarCantMiembros(ArbolDeLaVida *arbolDeLaVida){
    int miembros;
    for(int i=0; i<arbolDeLaVida->cantidadHumanos;i++){
        if (arbolDeLaVida->arrayDeLaVida[i]->apellido==apellido &&
        arbolDeLaVida->arrayDeLaVida[i]->pais==pais){
            miembros++;
        }
        
    }
    return miembros;
}
void Familia::annadirFamiliar(Humano * familiar){
        familiares[cantMiembrosActual]=familiar;
    }
//Demonios
    void Demonio::matarHumano(Humano *humano){
        humano->vivo=false;
        for (int i=0; i<cantFamilias;i++){
            Familia *fam= familias[i];
            if (humano->pais==fam->pais  &&humano->apellido==fam->pais){
                fam->annadirFamiliar(humano);
            }
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
    //falta validar que el bro esté vivo
}

void menuPublicarPorReligion(ArbolDeLaVida * arbol){
    string religion=seleccionarReligion();
    for (int i = 0; i < arbol->cantidadHumanos; i++){
        if (arbol->arrayDeLaVida[i]->creencia==religion && arbol->arrayDeLaVida[i]->vivo){
            arbol->enviarAPecar(arbol->arrayDeLaVida[i]->ID,
            arbol->arrayDeLaVida[i]->redesSociales[6]->nombreRedSocial,
            extraerPecadoConRedSocial(arbol->arrayDeLaVida[i]->redesSociales[6]->nombreRedSocial));
        }
    } 
}

void menuPublicarPorProfesion(ArbolDeLaVida * arbol){
    string profesion=seleccionarProfesion();
    string cantidad;
    cout<<"Ingrese la cantidad de redes a publicar: "<<endl;
    getline(cin, cantidad);
    for (int i = 0; i < arbol->cantidadHumanos; i++){
        if (arbol->arrayDeLaVida[i]->profesion==profesion && arbol->arrayDeLaVida[i]->vivo){
            for (int j = 0; j < stoi(cantidad); j++){
                arbol->enviarAPecar(arbol->arrayDeLaVida[i]->ID,
                arbol->arrayDeLaVida[i]->redesSociales[6-j]->nombreRedSocial,
                extraerPecadoConRedSocial(arbol->arrayDeLaVida[i]->redesSociales[6-j]->nombreRedSocial));
            }
        }
    }
}

void menuPublicarPorFamilia(ArbolDeLaVida * arbol){
    string pais=seleccionarPais();
    string apellido=seleccionarApellido();
    string cantidad;
    cout<<"Ingrese la cantidad de redes a publicar: "<<endl;
    getline(cin, cantidad); //entero entre 1 y 7 validar
    for (int i = 0; i < arbol->cantidadHumanos; i++){
        if (arbol->arrayDeLaVida[i]->apellido==apellido && arbol->arrayDeLaVida[i]->pais==pais && arbol->arrayDeLaVida[i]->vivo){
            for (int j = 0; j < stoi(cantidad); j++){
                arbol->enviarAPecar(arbol->arrayDeLaVida[i]->ID,
                arbol->arrayDeLaVida[i]->redesSociales[6-j]->nombreRedSocial,
                extraerPecadoConRedSocial(arbol->arrayDeLaVida[i]->redesSociales[6-j]->nombreRedSocial));
            }
        }
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
        menuPublicarPorReligion(arbol);
        break;
    case 3:
        menuPublicarPorProfesion(arbol);
        break;
    case 4:
        menuPublicarPorFamilia(arbol);
        break;
    default:
	    cout<<"La opción seleccionada no existe"<<endl;
        break;
    }
}


