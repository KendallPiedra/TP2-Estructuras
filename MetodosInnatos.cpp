#include "Estructuras.h"
#include "Funciones.cpp"

//HUMANO -------------------------------------------------------------------------------------------------
void Humano::inicializarPecados(){
    //0:Lujuria  
    //1:Gula
    //2:Avaricia
    //3:Pereza
    //4:Ira
    //5:Envidia
    //6:Soverbia 
    string pecadosCapitales[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    for (int i=0; i < 7; i++){
        pecados[i]= new Pecado(pecadosCapitales[i]);
    }
}

void Humano::ordenarRedesSociales(){
    for (int i = 0; i < 6; i++) {
        int minIdx = i;
        for (int j = i+1; j < 7; j++) {
            if (redesSociales[j]->gusto < redesSociales[minIdx]->gusto){
                minIdx = j;
            }
        }
        RedSocial * temp = redesSociales[minIdx];
        redesSociales[minIdx] = redesSociales[i];
        redesSociales[i] = temp;
    }
}

int Humano::determinarCantidadASumar(string redSocial){
    for (int i = 0; i < 7; i++){
        if(redesSociales[i]->nombreRedSocial==redSocial){
            return i+1;
        }
    }
    return 0;
}

void Humano::agregarPecado(string pecado, int cantidadAgregar){ //sujeto a cambios
    for (int i=0; i < 7; i++){
        if (pecados[i]->nombrePecado==pecado){
            pecados[i]->cantidad+=cantidadAgregar;
            totalPecados+=cantidadAgregar;
        }
    }
}

void Humano::inicializarRedesSociales(){
    string nombresRedes[]={"Tinder", "iFood", "LinkedIn", "Netflix", "Twitter", "Facebook", "Instagram"};
    for (int i=0; i < 7; i++){
        redesSociales[i]=new RedSocial(nombresRedes[i],generarNumerosAleatorios(100));
    }
    ordenarRedesSociales();
}

void Humano::imprimir(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Pais: "<<pais<<endl;
    cout<<"Creencia: "<<creencia<<endl;
    cout<<"Profesión: "<<profesion<<endl;
    cout<<"Nacimiento: "<<nacimieto<<endl;
    cout<<"Cantidad amigos maxima: "<<cantidadAmigos<<endl;
    cout<<"vivo: "<<vivo<<endl;
    cout<<"Pecados: "<<endl;
    //
    //
    imprimirPecados();
    imprimirRedesSociales();
    amigos->imprimir();
}

void Humano::publicarEnRedSocial(string redSocial, string pecado){
    NodoAmigo *tmp=amigos->primerNodo;
    while (tmp!=NULL){
        tmp->amigo->agregarPecado(pecado, tmp->amigo->determinarCantidadASumar(redSocial));
        tmp=tmp->siguiente;
    }
}

void Humano::imprimirPecados(){
    for (int i = 0; i < 7; i++){
        cout<<pecados[i]->nombrePecado<<": "<<pecados[i]->cantidad<<endl;
    }
}

void Humano::imprimirRedesSociales(){
    for (int i = 0; i < 7; i++){
        cout<<redesSociales[i]->nombreRedSocial<<": "<<redesSociales[i]->gusto<<endl;
    }
}

int Humano::extraerPecadosTotales(){
    int cantidadTotal=0;
    for (int i=0; i < 7; i++){
        cantidadTotal+=pecados[i]->cantidad;
    }
    return cantidadTotal;
}
// NODO ARBOL ----------------------------------------------------------------------------------------
void NodoArbol::imprimir(){
    cout<<humano->ID<<endl; //hacer función que imprima al humano**
}

// METODOS DE LA VIDA ---------------------------------------------------------------------------------
int ArbolDeLaVida::extraerIndiceHumano(Humano * humano){
    for(int i=0; i<cantidadHumanos;i++){
        if (arrayDeLaVida[i]->ID==humano->ID){
            return i;
        }
    }
    return -1;
}

Humano * ArbolDeLaVida::extraerHumano(int ID){
    for(int i=0; i<cantidadHumanos;i++){
        if (arrayDeLaVida[i]->ID==ID){
            return arrayDeLaVida[i];
        }
    }
    return NULL;
}

Humano * ArbolDeLaVida::extraerHumanoNombre(string _nombre, string _apellido){
    for(int i=0; i<cantidadHumanos;i++){
        if (arrayDeLaVida[i]->nombre==_nombre && arrayDeLaVida[i]->apellido==_apellido){
            return arrayDeLaVida[i];
        }
    }
    return NULL;
}

void ArbolDeLaVida::ordenarArrayDeLaVida(){
    for (int i = 0; i < cantidadHumanos-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < cantidadHumanos; j++) {
            if (arrayDeLaVida[j]->ID < arrayDeLaVida[minIdx]->ID){
                minIdx = j;
            }
        }
        Humano * temp = arrayDeLaVida[minIdx];
        arrayDeLaVida[minIdx] = arrayDeLaVida[i];
        arrayDeLaVida[i] = temp;
    }
}

void ArbolDeLaVida::insertar(Humano * humano){
    raiz = insertar(humano, raiz);
}

bool ArbolDeLaVida::validarID(int ID){
    for(int i=0; i<cantidadHumanos;i++){
        if (arrayDeLaVida[i]->ID==ID){
            return false;
        }
    }
    return true;
}
//  INSERTA RECURSIVAMENTE
NodoArbol* ArbolDeLaVida::insertar(Humano * humano, NodoArbol* nodo){
    if (nodo == NULL){
        return new NodoArbol(humano);
    }else if(nodo->humano->ID < humano->ID){ 
        // si el valor es mayor, llama recursivamente a insertar en el hijo derecho
        nodo->hijoderecho = insertar(humano, nodo->hijoderecho);
    }else if (nodo->humano->ID >= humano->ID){ 
        // en caso contrario, va al lado izquierdo
        nodo->hijoizquierdo = insertar(humano, nodo->hijoizquierdo);
    }
    return nodo;
}

void ArbolDeLaVida::inOrden(NodoArbol* nodo){
    if (nodo != NULL){
        inOrden(nodo->hijoizquierdo);
        cout <<"  "<< nodo->humano->ID <<"  "<<endl;
        inOrden(nodo->hijoderecho);
    }
}

int ArbolDeLaVida::contadorNodos(NodoArbol* nodo){
    if (nodo == NULL)
        return 0;
    else
        return 1+contadorNodos(nodo->hijoderecho)+contadorNodos(nodo->hijoizquierdo);
}        
// Hay que modificar un toque esta función
NodoArbol* ArbolDeLaVida::buscar (int IDhumano, NodoArbol* nodo){
    // cuando el nodo es nulo, quiere decir que all� debe
    // ubicar el valor, en un nuevo nodo
    if (nodo == NULL){
        return NULL;
    }else if (nodo->humano->ID == IDhumano){
        return nodo;
    }else if (nodo->humano->ID<IDhumano){
        // si el valor es mayor, llama recursivamente a insertar en el hijo
        // derecho
        return buscar(IDhumano, nodo->hijoderecho);
    }else{ //(nodo.dato >= valor)
     // en caso contrario, va al lado izquierdo
        return buscar(IDhumano, nodo->hijoizquierdo);
    }
}

int ArbolDeLaVida::altura (NodoArbol* nodo){
    if (nodo == NULL)
        return -1;
    else 
        return 1 + maximo(altura(nodo->hijoizquierdo),altura(nodo->hijoderecho));
}
// borrar
NodoArbol* ArbolDeLaVida::mayor (NodoArbol* arbol){
    if (arbol == NULL)
        return NULL;
    else if (arbol->hijoderecho == NULL)
        return arbol;
    else
        return mayor (arbol->hijoderecho);
}

int ArbolDeLaVida::extraerCantidadNodos(){
    int cantidadNodos=calcularPorcentaje(cantidadHumanos);
    cout<<cantidadNodos<<endl;
    while (!esPotenciaDeDos(cantidadNodos)){
        cantidadNodos++;
    }
    cout<<cantidadNodos<<endl;
    if (cantidadNodos!=1){
        cantidadNodos--;
    }
    return cantidadNodos;
}

void ArbolDeLaVida::crearGeneracionHumanos(int cantidadAGenerar){
    if (cantidadHumanos+cantidadAGenerar<=1000){
        int ID;
        string nombre, apellido, profesion, creencia, pais, nacimiento;
        for (int i = cantidadHumanos; i < cantidadAGenerar+cantidadHumanos; i++){
            nombre=extraerLineaAleatoria("nombres.txt",1000);
            apellido=extraerLineaAleatoria("apellidos.txt",30);
            profesion=extraerLineaAleatoria("profesiones.txt",21);
            creencia=extraerLineaAleatoria("creencias.txt",10);
            pais=extraerLineaAleatoria("paises.txt",20);
            nacimiento=obtenerFechaYHoraActual();
            do{
                ID=generarNumerosAleatorios(99999);
            } while (!validarID(ID));
            arrayDeLaVida[i]= new Humano(ID,nombre,apellido,pais,creencia,profesion,nacimiento,generarNumerosAleatorios(100));
            arrayDeLaVida[i]->inicializarPecados();
            arrayDeLaVida[i]->inicializarRedesSociales();
        }
        cantidadHumanos+=cantidadAGenerar;
        generarAmigos();
        ordenarArrayDeLaVida();
        raiz=NULL;
        construirArbol(0,cantidadHumanos,extraerCantidadNodos()-1, 0);
    }
}

int ArbolDeLaVida::construirArbol(int inicio, int fin,int cantidadDeseada, int contador){
    if (inicio <= fin && contador<=cantidadDeseada) {
        int centro = (inicio + fin) / 2;
        Humano *humanoCentral = arrayDeLaVida[centro];
        insertar(humanoCentral);
        contador++;
        contador = construirArbol(inicio, centro - 1, cantidadDeseada, contador);
        contador = construirArbol(centro + 1, fin, cantidadDeseada, contador);
    }
    return contador;
}

void ArbolDeLaVida::imprimir(){
    cout<<"---------------- ÁRBOL ----------------"<<endl;
    inOrden(raiz);
    cout<<"\n--------------- HUMANOS ------------------"<<endl;
    for (int i = 0; i < cantidadHumanos; i++){
        arrayDeLaVida[i]->imprimir();
        cout<<"---------------------------------------"<<endl;
    }
}
//BORRAAAAR
// NodoArbol* Arbol::borrarElemento(int ele){
//     raiz = borrarElemento(ele, raiz);
//     return raiz;
// }
// NodoArbol* Arbol::borrarElemento(int ele, NodoArbol* arbol){
//     if (arbol == NULL){
//         return NULL;
//     }
//     else if (ele < arbol->dato)
//         arbol->hijoizquierdo = borrarElemento(ele, arbol->hijoizquierdo);
//     else if (ele > arbol->dato)
//         arbol->hijoderecho = borrarElemento(ele, arbol->hijoderecho);
//     else if (arbol->hijoizquierdo == NULL && arbol->hijoderecho == NULL)
//         arbol = NULL;
//     else if (arbol->hijoizquierdo == NULL)
//         arbol = arbol->hijoderecho;
//     else if (arbol->hijoderecho == NULL)
//         arbol = arbol->hijoizquierdo;
//     else{
//         NodoArbol* max = mayor(arbol->hijoizquierdo); // mayor de los menores
//         arbol->hijoizquierdo = borrarElemento(max->dato, arbol->hijoizquierdo);
//         arbol->dato = max->dato;
//     }
//     return arbol;   
// }
//</BORRAAAAA>

//NODO PECADO -------------------------------------------------------------------------------------------

//LISTA AMIGUIS -----------------------------------------------------------------------------------------
void NodoAmigo::imprimir(){
    amigo->imprimir();
}

void ListaBesties::insertarInicio(Humano *amigo){
    if (primerNodo==NULL)
	    primerNodo=ultimoNodo=new NodoAmigo(amigo);
    else{
	    primerNodo->anterior= new NodoAmigo(amigo);
	    primerNodo->anterior->siguiente=primerNodo;
	    primerNodo=primerNodo->anterior;
    }
}

void ListaBesties::insertarFinal(Humano *amigo){
    if (primerNodo==NULL)
	    primerNodo=ultimoNodo=new NodoAmigo(amigo);
    else{
	    ultimoNodo->siguiente= new NodoAmigo(amigo);
	    ultimoNodo->siguiente->anterior=ultimoNodo;
	    ultimoNodo=ultimoNodo->siguiente; 
    }
}

NodoAmigo * ListaBesties::borrarAlFinal(){
	NodoAmigo * borrado=ultimoNodo;
	if (primerNodo!=NULL){
		if (primerNodo==ultimoNodo){
			primerNodo=ultimoNodo=NULL;
    	}else{
        	ultimoNodo=ultimoNodo->anterior;
			borrado->anterior=NULL;
			ultimoNodo->siguiente=NULL;
    	}
	}
    return borrado;
}

int ListaBesties::largo(){
	NodoAmigo * tmp = primerNodo;
    int contador=0;
    while(tmp!=NULL){
	    contador++;
	    tmp=tmp->siguiente;
    }
	return contador;
}

bool ListaBesties::tieneAmigo(int IDAmigo){
    NodoAmigo * tmp = primerNodo;
    while(tmp!=NULL){
	    if(IDAmigo==tmp->amigo->ID){
            return true;
        }
	    tmp=tmp->siguiente;
    }
	return false;
}

void ListaBesties::imprimir(){
    cout<<"--------------------Lista Besties--------------------"<<endl;
    NodoAmigo * tmp = primerNodo;
    while(tmp!=NULL){
	    cout<<"-->"<<tmp->amigo->nombre<<" "<<tmp->amigo->apellido<<endl;
        tmp=tmp->siguiente;
    }
    cout<<"-----------------------------------------------------"<<endl;
}

void ListaBesties::imprimirConPecados(){
    cout<<"--------------------*Lista Besties*--------------------"<<endl;
    NodoAmigo * tmp = primerNodo;
    while(tmp!=NULL){
	    tmp->amigo->imprimir();
        tmp=tmp->siguiente;
    }
    cout<<"-----------------------------------------------------"<<endl;
}

// BITACORA DE CONDENACIÓN ---------------------------------------------------------------------------------------------
void BitacoraCondenacion::insertarFinal(int indice, Humano * humano, string pecado){
    // cout<<humano->sacarCantidadPecado(pecado)<<endl;
    if (primerNodo==NULL)
	    primerNodo=ultimoNodo=new NodoBitacora(indice, humano, pecado, obtenerFechaYHoraActual(), extraerDemonioConPecado(pecado), humano->sacarCantidadPecado(pecado));
    else{
	    ultimoNodo->siguiente= new NodoBitacora(indice, humano, pecado, obtenerFechaYHoraActual(), extraerDemonioConPecado(pecado), humano->sacarCantidadPecado(pecado));
	    ultimoNodo->siguiente->anterior=ultimoNodo;
	    ultimoNodo=ultimoNodo->siguiente; 
    }
}

void BitacoraCondenacion::insertarFinalCielo(int indice, Humano * humano, string angel, NodoCelestial *angelEnviado){
    if (primerNodo==NULL){
	    primerNodo=ultimoNodo=new NodoBitacora(indice, humano, "Total", obtenerFechaYHoraActual(), angel, humano->extraerPecadosTotales());
        ultimoNodo->angel=angelEnviado;
    }else{
	    ultimoNodo->siguiente= new NodoBitacora(indice, humano, "Total", obtenerFechaYHoraActual(), angel, humano->extraerPecadosTotales());
	    ultimoNodo->siguiente->anterior=ultimoNodo;
	    ultimoNodo=ultimoNodo->siguiente; 
        ultimoNodo->angel=angelEnviado;
    }
}

// FAMILIAS ------------------------------------------------------------------------------------------------------------
void ArbolDeLaVida::insertar(Humano * humano){
    raiz = insertar(humano, raiz);
}

bool ArbolDeLaVida::validarID(int ID){
    for(int i=0; i<cantidadHumanos;i++){
        if (arrayDeLaVida[i]->ID==ID){
            return false;
        }
    }
    return true;
}
//  INSERTA RECURSIVAMENTE
NodoArbol* ArbolDeLaVida::insertar(Humano * humano, NodoArbol* nodo){
    if (nodo == NULL){
        return new NodoArbol(humano);
    }else if(nodo->humano->ID < humano->ID){ 
        // si el valor es mayor, llama recursivamente a insertar en el hijo derecho
        nodo->hijoderecho = insertar(humano, nodo->hijoderecho);
    }else if (nodo->humano->ID >= humano->ID){ 
        // en caso contrario, va al lado izquierdo
        nodo->hijoizquierdo = insertar(humano, nodo->hijoizquierdo);
    }
    return nodo;
}

// NODO CELESTIAL ------------------------------------------------------------------------------------------------------
void NodoCelestial::imprimirCelestialmente(){
    cout<<"------------------------- NODO CELESTIAL ---------------------------"<<endl;
    // cout<<"Humano: "<<humanoSalvado->nombre<<" "<<humanoSalvado->apellido<<endl;
    // cout<<"ID Humano: "<<humanoSalvado->ID<<endl;
    cout<<"Nombre Angelical: "<<nombreAngel<<endl;
    cout<<"Versión: "<<version<<endl;
    cout<<"Generación: "<<generacion<<endl;
}

// ARBOL ANGELICAL -----------------------------------------------------------------------------------------------------
void ArbolAngelical::generarPrimerNivel(){
    raiz->angelIzquierdo=new NodoCelestial("Serafines",0);
    raiz->angelCentral=new NodoCelestial("Querubines",0);
    raiz->angelDerecho=new NodoCelestial("Tronos",0);
}

void ArbolAngelical::generarVersiones(NodoCelestial *nodo, string nombre){
    if (nodo == NULL) 
        return;

    if (nodo->angelIzquierdo == NULL && nodo->angelCentral == NULL && nodo->angelDerecho == NULL && nodo->nombreAngel==nombre) {
        nodo->version=numeroVersion+1;
        numeroVersion++;
    }

    generarVersiones(nodo->angelIzquierdo, nombre);
    generarVersiones(nodo->angelCentral, nombre);
    generarVersiones(nodo->angelDerecho, nombre);
}

void ArbolAngelical::generarNuevoNivel(NodoCelestial *nodo){
    string nombresAngelicales[]={"Miguel","Nuriel","Aniel","Rafael","Gabriel","Shamsiel","Raguel", "Uriel", "Azrael", "Sariel"};
    if (nodo == NULL) 
        return;

    if (nodo->angelIzquierdo == NULL && nodo->angelCentral == NULL && nodo->angelDerecho == NULL) {
        nodo->angelIzquierdo = new NodoCelestial(nombresAngelicales[generarNumerosAleatorios(10)-1], nodo->generacion + 1);
        nodo->angelCentral = new NodoCelestial(nombresAngelicales[generarNumerosAleatorios(10)-1], nodo->generacion + 1);
        nodo->angelDerecho = new NodoCelestial(nombresAngelicales[generarNumerosAleatorios(10)-1], nodo->generacion + 1);
        return;
    }

    generarNuevoNivel(nodo->angelIzquierdo);
    generarNuevoNivel(nodo->angelCentral);
    generarNuevoNivel(nodo->angelDerecho);
}

void ArbolAngelical::imprimirPreOrden(NodoCelestial *nodo){
    if (nodo != NULL){
        nodo->imprimirCelestialmente();
        imprimirPreOrden(nodo->angelIzquierdo);
        imprimirPreOrden(nodo->angelCentral);
        imprimirPreOrden(nodo->angelDerecho);
    }
}

string ArbolAngelical::organizarPreOrden(NodoCelestial *nodo, string texto){
    if (nodo != NULL){
        texto+=convertirAngelAString(nodo);
        texto+=organizarPreOrden(nodo->angelIzquierdo, texto);
        texto+=organizarPreOrden(nodo->angelCentral, texto);
        texto+=organizarPreOrden(nodo->angelDerecho, texto);
        return texto;
    }else{
        return "";
    }
}