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
    Humano * humano=NULL;
    for (int i=0; i < cantidadHumanos; i++){
        humano=arrayDeLaVida[i];
        humano->agregarAmigos(arrayDeLaVida, cantidadHumanos);
        humano->inicializarPecados();
        humano->inicializarRedesSociales();
    }
}

//MENUS -------------------------------------------------------------------------------------------------
int menuPrincipal(){
    string opcion;
    do{
        cout<<"------------------------------- MENÚ -------------------------------"<<endl;
	    cout<<"1: Crear Generación de Humanos"<<endl;
	    cout<<"2: Publicar en Redes Sociales"<<endl;
	    cout<<"3: La Condenación"<<endl;
	    cout<<"4: El Infierno"<<endl;
	    cout<<"5: La Salvación"<<endl;
	    cout<<"6: El Cielo"<<endl;
	    cout<<"7: Consultas"<<endl;
	    cout<<"0: SALIR"<<endl;
	    getline(cin,opcion);
    } while (!esInt(opcion));
	return stoi(opcion);
}

void menuPublicarPorHumano(){

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
    switch (stoi(opcion))
    {
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


