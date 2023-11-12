#include "MetodosInnatos.cpp"

//METODOS HUMANOS -------------------------------------------------------------------------------------
void Humano::agregarAmigos(Humano * arrayDeLaVida[], int cantHumanosActual){
    Humano * candidatoAmigo=NULL;
    int cantProvisional=cantidadAmigos-amigos->largo();
    for (int i=0; i < cantHumanosActual; i++){
        candidatoAmigo=arrayDeLaVida[i];
        if (cantProvisional==0){
            break;
        }else if (candidatoAmigo->ID!=ID && candidatoAmigo->pais==pais && 
        (candidatoAmigo->creencia==creencia || candidatoAmigo->apellido==apellido || candidatoAmigo->profesion==profesion)){
            if(!amigos->tieneAmigo(candidatoAmigo->ID)){
                amigos->insertarFinal(candidatoAmigo);
                cantProvisional--;
            }
        }
    }
}

int Humano::sacarIndicePecado(string pecado){
    for (int i=0; i<7;i++){
        if (pecados[i]->nombrePecado==pecado){
            return i;
        }
    }
    return -1;
}

int Humano::sacarCantidadPecado(string pecado){
    // cout<<"Se llama a sacar cantidad de pecado"<<endl;
    // cout<<pecado<<endl;
    int iPecado=sacarIndicePecado(pecado);
    // cout<<"iPecado:"<<iPecado<<endl;
    // cout<<"cantidad:"<<pecados[iPecado]->cantidad<<endl;

    return pecados[iPecado]->cantidad;

}

//pasar a innatos!!!!
string Humano::convertirPecadosAString() {
    string sPecados = "";
    for (int i = 0; i < 7; i++) {
        sPecados += pecados[i]->nombrePecado + ": " + to_string(pecados[i]->cantidad) + "\n";
    }
    return sPecados;
}
string Humano::convertirRedesSocialesAString(){
    string sRedesSociales = "";
    for (int i = 0; i < 7; i++) {
        sRedesSociales += redesSociales[i]->nombreRedSocial + ": " + to_string(redesSociales[i]->gusto) + "\n";
    }
    return sRedesSociales;
}

string Humano::convertirAString(){
    string datos="";
    datos += "ID: " + to_string(ID) + "\n";
    datos += "Nombre: " + nombre + "\n";
    datos += "Apellido: " + apellido + "\n";
    datos += "Pais: " + pais + "\n";
    datos += "Creencia: " + creencia + "\n";
    datos += "Profesión: " + profesion + "\n";
    datos += "Nacimiento: " + nacimieto + "\n";
    datos += "Cantidad amigos maxima: " + to_string(cantidadAmigos) + "\n";
    datos += "Pecados:\n";
    datos += convertirPecadosAString();//
    datos += convertirRedesSocialesAString();//
    datos += amigos->convertirAmigosAString();//
    return datos;
}

string Humano::convertirAStringCelestial(){
    string datos="";
    datos += "ID: " + to_string(ID) + "\n";
    datos += "Nombre: " + nombre + "\n";
    datos += "Apellido: " + apellido + "\n";
    datos += "Pais: " + pais + "\n";
    datos += "Creencia: " + creencia + "\n";
    datos += "Profesión: " + profesion + "\n";
    datos += "Nacimiento: " + nacimieto + "\n";
    datos += "Angel que lo Salvó: " + angelQueLoSalvo->nombreAngel + " ("+ to_string(angelQueLoSalvo->version)+")" "\n";
    datos += "Generación del ángel: "+ to_string(angelQueLoSalvo->generacion) + "\n";
    datos += "Cantidad amigos maxima: " + to_string(cantidadAmigos) + "\n";
    datos += "Pecados:\n";
    datos += convertirPecadosAString();//
    datos += convertirRedesSocialesAString();//
    datos += amigos->convertirAmigosAString();//
    return datos;
}

//Metodos amigos
//pasar a innatos!!
string ListaBesties::convertirAmigosAString(){
    string sAmigos = "--------------------Lista Amigos--------------------\n";
    NodoAmigo *tmp = primerNodo;
    while (tmp != NULL) {
        sAmigos += "-->" + tmp->amigo->nombre + " " + tmp->amigo->apellido + "\n";
        tmp = tmp->siguiente;
    }
    sAmigos += "-----------------------------------------------------\n";
    return sAmigos;
}
//METODOS DE LA VIDA ----------------------------------------------------------------------------------
void ArbolDeLaVida::generarAmigos(){
    for (int i=0; i < cantidadHumanos; i++){
        arrayDeLaVida[i]->agregarAmigos(arrayDeLaVida, cantidadHumanos);
        
    }
}
//

int ArbolDeLaVida::sacarIndicePecado(string pecado){
    return arrayDeLaVida[0]->sacarIndicePecado(pecado);
}

int* ArbolDeLaVida::sacarIndicesOrdenadosSegunPecado(string pecado) {
    int* indices = new int[cantidadHumanos];
    for (int i = 0; i < cantidadHumanos; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < cantidadHumanos - 1; i++) {
        int maxIndice = i;
        for (int j = i + 1; j < cantidadHumanos; j++) {
            if (arrayDeLaVida[indices[j]]->sacarCantidadPecado(pecado) > arrayDeLaVida[indices[maxIndice]]->sacarCantidadPecado(pecado)) {
                maxIndice = j;
            }
        }
        int temp = indices[i];
        indices[i] = indices[maxIndice];
        indices[maxIndice] = temp;
    }
    return indices;
}

Humano** ArbolDeLaVida::sacarPorcentajeMasPecador(string pecado) {//PROBAR
    int * indices = sacarIndicesOrdenadosSegunPecado(pecado);
    int cantidadPecadores = PorcentajeACantidad(5, cantidadHumanos);
    Humano** humanosPecadores = new Humano*[cantidadPecadores];
    int j=0;
    for (int i = 0; i < cantidadPecadores; i++) {
        // cout<<"i: "<<i<<endl;
        // cout<<"j: "<<j<<endl;
        bool annadio=false;
        
        while(annadio==false){

            if(arrayDeLaVida[indices[j]]->vivo){
                //esta vivo
                humanosPecadores[i] = arrayDeLaVida[indices[j]];
                annadio=true;
                j++;
            } else {j++;}//no esta vivo. Debe intentarlo con el siguiente  
        } 
    }
    return humanosPecadores;
}

// No se que hace este método aqui pero me da mieo moverlo :)
void ArbolDeLaVida::enviarAPecar(int ID, string redSocial, string pecado){
    for (int i=0; i < cantidadHumanos; i++){
        if(arrayDeLaVida[i]->ID==ID && arrayDeLaVida[i]->vivo){
            arrayDeLaVida[i]->publicarEnRedSocial(redSocial, pecado);
        }
    }
}

//FAMILIAS ------------------------------------------------------------------------------------------------------------------
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

void Familia::ordenarHeap(int k){//La primera vez k es 1
    int hijoIz=2*k;
    int hijoDer=2*k+1;
    if (hijoIz<=cantMiembrosActual){
        if(familiares[hijoIz-1]->sacarCantidadPecado(pecado)>
        familiares[k]->sacarCantidadPecado(pecado)){
            Humano* temp=familiares[k-1];
            familiares[k-1]= familiares[hijoIz-1];
            familiares[hijoIz-1]=temp;
        }
        ordenarHeap(2*k);
        
    }
    if(hijoDer<=cantMiembrosActual){
        if(familiares[hijoDer-1]->sacarCantidadPecado(pecado)>
        familiares[k-1]->sacarCantidadPecado(pecado)){
            Humano* temp=familiares[k-1];
            familiares[k-1]= familiares[hijoDer-1];
            familiares[hijoDer-1]=temp;
        }
        ordenarHeap(2*k+1);
    }
    
}
void Familia::annadirFamiliar(Humano * familiar){
        familiares[cantMiembrosActual]=familiar;
        cantMiembrosActual++;
        ordenarHeap(1);
    }
void Familia::borrarRaiz(){
    familiares[0]=familiares[cantMiembrosActual-1];
    familiares[cantMiembrosActual-1]=NULL;
    cantMiembrosActual--;
    ordenarHeap(1);
}

Humano * Familia::sacarRaiz(){
    Humano* humano=familiares[0];
    return humano;
}
//DEMONIOS ------------------------------------------------------------------------------------------------------------

void Demonio::insertarEnFamiliaNueva(Humano*humano, ArbolDeLaVida * ADLV){
    familias[cantFamilias]=new Familia(humano->apellido,humano->pais,pecado, ADLV);

    familias[cantFamilias]->annadirFamiliar(humano);
    cantFamilias++;
}

void Demonio::matarHumano(Humano *humano, ArbolDeLaVida * ADLV){
    humano->vivo=false;
    Familia *fam;
    bool insertado=false;
    for (int i=0; i<cantFamilias;i++){
        fam= familias[i];
        if (humano->pais==fam->pais  &&humano->apellido==fam->apellido
        ){
            fam->annadirFamiliar(humano);
            insertado=true;
        }
    }
    if(insertado==false){
    insertarEnFamiliaNueva(humano, ADLV);
    }
}

int Demonio::calcularCantidadHumanos(){
    int cantidad=0;
    cout<<"cantidad fam: "<<cantFamilias<<endl;
    for (int i=0; i<cantFamilias;i++){
        cout<<cantidad<<endl;

        cantidad+=familias[i]->cantMiembrosActual;
        cout<<"cantidad miembros: "<<familias[i]->cantMiembrosActual<<endl;
    }
    cout<<cantidad<<endl;
    return cantidad;
}

int Demonio::calcularMaximoPecados() {
    int maxPecado = -1; // Inicializa el valor máximo como negativo, asumiendo que los pecados son números no negativos
    for (int i = 0; i < cantFamilias; i++) {
        Familia* familia = familias[i];
        for (int j = 0; j < familia->cantMiembrosActual; j++) {
            Humano* familiar = familia->familiares[j];
            if (familiar->sacarCantidadPecado(pecado) > maxPecado) {
                maxPecado = familiar->sacarCantidadPecado(pecado);
            }
        }
    }
    return maxPecado;
}

int Demonio::calcularMinimoPecados() {
    int minPecado = INT_MAX; // Inicializa el valor mínimo como el máximo valor posible
    for (int i = 0; i < cantFamilias; i++) {
        Familia* familia = familias[i];
        for (int j = 0; j < familia->cantMiembrosActual; j++) {
            Humano* familiar = familia->familiares[j];
            if (familiar->sacarCantidadPecado(pecado) < minPecado) {
                minPecado = familiar->sacarCantidadPecado(pecado);
            }
        }
    }
    return minPecado;
}

int Demonio::calcularPromedioPecados() {
    int sumaPecados = 0;
    int cantidadPecados = 0;

    for (int i = 0; i < cantFamilias; i++) {
        Familia* familia = familias[i];
        for (int j = 0; j < familia->cantMiembrosActual; j++) {
            Humano* familiar = familia->familiares[j];
                sumaPecados += familiar->sacarCantidadPecado(pecado); // Suponiendo que el pecado que deseas calcular es el primer pecado
                cantidadPecados++;
        }
    }
    // Evitar la división por cero
    if (cantidadPecados == 0) {
        return 0; // No hay pecados para calcular el promedio
    }
    int promedio = sumaPecados / cantidadPecados;
    return promedio;
}


Humano ** Demonio::sacarListaDeHumanos(){
    Humano** listaHumanos=new Humano*[calcularCantidadHumanos()];
    int k=0;
    for (int i=0;i<cantFamilias;i++){
        for(int j=0;j<familias[i]->cantMiembrosActual;j++){
            listaHumanos[k]=familias[i]->familiares[j];
            k++;
        }
    }
    cout<<"cantidad de familias"<< cantFamilias<<endl;

    return listaHumanos;
}

Humano ** Demonio::sacarListaDeLosMasPecadores(){
    // cout << "Entra a la funcion sacarListaDeLosMasPecadores" << endl;
    Humano** listaHumanos = sacarListaDeHumanos();
    // cout << "Se logra sacar la lista de humanos" << endl;
    int cantidad = calcularCantidadHumanos();
    // cout << "Cantidad de humanos: " << cantidad << endl;
    for (int i = 0; i < cantidad-1; i++) {
        int maxIdx = i;
        for (int j = i+1; j < cantidad; j++) {
            // cout<<"I:"<<i<<endl;
            // cout<<"J:"<<j<<endl;
            // cout<<pecado<<endl;
            // cout<<listaHumanos[j]->sacarCantidadPecado(pecado)<<endl; 
            // cout<<listaHumanos[maxIdx]->sacarCantidadPecado(pecado)<<endl;

            if (listaHumanos[j]->sacarCantidadPecado(pecado) > listaHumanos[maxIdx]->sacarCantidadPecado(pecado)){
                maxIdx = j;
            }
            // cout<<maxIdx<<endl;
        }
        Humano * temp = listaHumanos[maxIdx];
        listaHumanos[maxIdx] = listaHumanos[i];
        listaHumanos[i] = temp;
    }

    // cout << "Lista de los más pecadores ordenada correctamente" << endl;

    return listaHumanos;
}

Humano * Demonio::mostrarHumanoRaiz(int idxFamilia){
    return familias[idxFamilia]->sacarRaiz();
}

Humano * Demonio::sacarHumano(int idxFamilia){
    Humano*humano=mostrarHumanoRaiz(idxFamilia);
    familias[idxFamilia]->borrarRaiz();
    return humano;
}
//INFIERNO ---------------------------------------------------------------------------------------------------------------------
void Infierno::generarBitacoraCondenacion(Humano * humano, string pecado){ //esta ordenado por demonio, pero del mas a menos pecador no
    bitacora->insertarFinal(ADLV->extraerIndiceHumano(humano), humano, pecado);
}

void Infierno::enviarDemonio(int posicionD){
    cout<<"enviardemonio"<<endl;
    cout<<demonios[posicionD]->nombre<<endl;
    string pecado= demonios[posicionD]->pecado;
    cout<<pecado<<endl;
    Humano** condenados =ADLV->sacarPorcentajeMasPecador(pecado);
    cout<<"Se saca el porcentaje mas pecador"<<endl;
    int cantidadCondenados = PorcentajeACantidad(5, ADLV->cantidadHumanos);
    cout<<"cantidad condenados: "<< cantidadCondenados<<endl;
    for (int i=0; i<cantidadCondenados;i++){
        if (condenados[i] == nullptr) {
            // No quedan condenados
            cout<<"No quedan condenados"<<endl;
            break;
        }
        demonios[posicionD]->matarHumano(condenados[i],ADLV);
        generarBitacoraCondenacion(condenados[i], pecado);
    }
} 

string Infierno::crearArchivoBitacora(){
    ofstream archivo;
    string nombre=obtenerFechaYHoraActual()+".txt";
	archivo.open(nombre,ios::out); 
	if (archivo.fail()){
		cout<<"No escribí el archivo"<<endl;//que sad
		exit(1);
	}
    NodoBitacora * tmp= bitacora->primerNodo;
    while (tmp!=NULL){
        archivo<<"\n"<<tmp->fechayHora<<"\tHumano: "<<tmp->indice<<"\t"<<tmp->nombreYApellido<<"\t"<<tmp->pais<<endl;
	    archivo<<"Murió el "<<tmp->fechayHora<<endl;
        archivo<<"Condenado por "<<tmp->pecado->cantidad<<" pecados de "<<tmp->pecado->nombrePecado<<
        " por el demonio "<<tmp->demonio<<endl;
        tmp=tmp->siguiente;
    }
	archivo.close();
    bitacora->primerNodo=bitacora->ultimoNodo=NULL; 
    return nombre;
} 

string Infierno::realizarCondenacionGeneral(){
    for (int i; i<7;i++){
        enviarDemonio(i);
        // cout<<"no"<<endl;
    }
    return crearArchivoBitacora();
}

void Infierno::generarConsultaInfernal(){
    ofstream archivo;
    archivo.open("ConsultaInfernal.txt",ios::out);
    archivo<<"---------------------------- INFIERNO --------------------------------"<<endl;
    archivo<<"\nTotal actual de humanos residentes en el Infierno:\t"<<sacarCantidadDeHumanos()<<"\n"<<endl;
    archivo<<"Cantidad actual de familias residentes en el Infierno:\t"<<sacarCantidadDeFamilias()<<endl;
    for (int i=0; i<7; i++){
        archivo<<"-------------------------------- DEMONIO -------------------------------"<<endl;
        archivo<<"Nombre Demonio:\t"<<demonios[i]->nombre<<"\nPecado: \t"<<demonios[i]->pecado<<endl;
        archivo<<"Cantidad de humanos condenados:\t"<<demonios[i]->calcularCantidadHumanos()<<endl;
        archivo<<"Promedio de pecados:\t"<<demonios[i]->calcularPromedioPecados()<<endl;
        archivo<<"Maximo de pecados:\t"<<demonios[i]->calcularMaximoPecados()<<endl;
        archivo<<"Minimo de pecados:\t"<<demonios[i]->calcularMinimoPecados()<<endl;
        // cout<<"se pusieron los datos del demonio"<<endl;
        // cout<<"se calculan los humanos"<<endl;
        int cantidadHumanos = demonios[i]->calcularCantidadHumanos();
        // cout<<"sacar lista de los mas pecadores"<<endl;
        Humano**listaOrdenadaHumanos=demonios[i]->sacarListaDeLosMasPecadores();
        // cout<<"se saco la lista de los mas pecadores"<<endl;
        archivo<<"Humanos Condenados:\n------------------------------------------------------------------------"<<endl;
        // cout<<"alooooooooo"<<endl;
        for (int j=0; j< cantidadHumanos;j++){
            // cout<<"se intenta pasar un humano a string"<<endl;
            archivo<<listaOrdenadaHumanos[j]->convertirAString()<<endl;
            archivo<<"------------------------------------------------------------------------------------------"<<endl;
        }
    }
    archivo.close();
        //MOSTRAR LISTA DE MAS PECADORES A MENOS DE SU HEAP
}
int Infierno::sacarCantidadDeFamilias(){
    int cantFamilias=0;
    for (int i=0;i<7;i++){
        cantFamilias += demonios[i]->cantFamilias;
    }
    return cantFamilias;
}

Humano** Infierno::sacarListaDeRaicesDemoniacas(){
    Humano** humanosRaiz= new Humano*[sacarCantidadDeFamilias()];
    int k=0;
    for (int i=0;i<7;i++){
        for(int j=0; j<demonios[i]->cantFamilias;j++){
            humanosRaiz[k]=demonios[i]->mostrarHumanoRaiz(j);
            k++;
        }
    }
    return humanosRaiz;
}

//retorna el ID Del humano
int Infierno::buscarHumanoMasPecador(){
    int cantRaices= sacarCantidadDeFamilias();
    Humano** humanosRaiz= sacarListaDeRaicesDemoniacas();
    
    Humano* humanoMasPecador = humanosRaiz[0];
    for (int i = 1; i < cantRaices; ++i) {
        if (humanosRaiz[i]->totalPecados > humanoMasPecador->totalPecados) {
            humanoMasPecador = humanosRaiz[i];
        }
    }

    return humanoMasPecador->ID;
}

//saca el humano (lo borra de su heap) y lo retorna
//su parametro es el ID del humano
//solo funciona con las raices de los heaps
Humano* Infierno::sacarHumano(int IDHumano){
    for(int i=0; i<7;i++){
        for(int j=0;j<demonios[i]->cantFamilias;j++){
            Humano*humano=demonios[i]->mostrarHumanoRaiz(j);
            if(humano->ID==IDHumano){
                return demonios[i]->sacarHumano(j);
            }
        }
    }
    return NULL;
}


Humano* Infierno::sacarHumanoMasPecador(){
    return sacarHumano(buscarHumanoMasPecador());
}

//retorna el indice del humano en la familia
//si el humano no esta en la familia retorna -1
int Familia::buscarFamiliarPorID(int ID){
    for (int i=0; i<cantMiembrosActual;i++){
        if(familiares[i]->ID==ID){
            return i;
        }
    }
    return -1;
}

//retorna el indice de la familia en el que se entruentra el humano
//si el humano no esta en el demonio retorna -1
int Demonio::buscarFamiliaDelAlmaCaptiva(int ID){
    for (int i=0; i<cantFamilias;i++){
        if(familias[i]->buscarFamiliarPorID(ID)!=-1){
            return i;
        }
    }
    return -1;
}

//retorna el indice del demonio en el que se entruentra el humano
//si el humano no esta en el infierno retorna -1
int Infierno::buscarDemonioConAlmaCaptiva(int ID){
    for (int i;i<7;i++){
        if (demonios[i]->buscarFamiliaDelAlmaCaptiva(ID)!=-1){
            return i;
        }
    }
    return -1;
}



int Infierno::sacarCantidadDeHumanos(){
    int humanosTotales;
    for (int i; i<7;i++){
        humanosTotales+=demonios[i]->calcularCantidadHumanos();
    }
    return humanosTotales;
}

//ARBOL CELESTIAL --------------------------------------------------------------------------------------
void ArbolAngelical::invocarAngeles(){
    string nombresAngelicales[]={"Miguel","Nuriel","Aniel","Rafael","Gabriel",
    "Shamsiel","Raguel", "Uriel", "Azrael", "Sariel"};
    generarNuevoNivel(raiz);
    for (int i = 0; i < 10; i++){
        generarVersiones(raiz,nombresAngelicales[i]);
        numeroVersion=0;
    }
}

int ArbolAngelical::contarHojas(NodoCelestial* nodo) {
    if (nodo == NULL)
        return 0;
    if (nodo->angelIzquierdo==NULL && nodo->angelDerecho==NULL && nodo->angelCentral==NULL)
        return 1;
    return contarHojas(nodo->angelIzquierdo)+contarHojas(nodo->angelCentral)+contarHojas(nodo->angelDerecho);
}

NodoCelestial * ArbolAngelical::salvarHumano(NodoCelestial *nodo, Humano * humanoASalvar){
    if (nodo == NULL) 
        return NULL;
    if (nodo->angelIzquierdo == NULL && nodo->angelCentral == NULL && nodo->angelDerecho == NULL &&
        nodo->humanoSalvado == NULL) {
        nodo->humanoSalvado = humanoASalvar;
        return nodo;
    }
    NodoCelestial *resultIzquierdo = salvarHumano(nodo->angelIzquierdo, humanoASalvar);
    if (resultIzquierdo != NULL) 
        return resultIzquierdo;
    NodoCelestial *resultCentral = salvarHumano(nodo->angelCentral, humanoASalvar);
    if (resultCentral != NULL) 
        return resultCentral;
    NodoCelestial *resultDerecho = salvarHumano(nodo->angelDerecho, humanoASalvar);
    return resultDerecho;
}

//CIELO----------------------------------------------------------------

int Cielo::calcularPosicionEnTabla(int ID){
    return ID%1000;
}

void Cielo::insertarEnTablaHash(Humano *humano){
    int posicion= calcularPosicionEnTabla(humano->ID);
    r=tablaSacra[posicion]->insert(r,humano);//esto funciona muy raro, el puntero se declara en la estructura, se cambia su valor 
    //y luego se inserta a si mismo, yo lo llame basandome en la muestra que se habia hecho en  EstructuraAVL
}

void Cielo::generarBitacoraSalvacion(Humano * humano, string angel, NodoCelestial *angelEnviado){ //esta ordenado por demonio, pero del mas a menos pecador no
    bitacora->insertarFinalCielo(infierno->ADLV->extraerIndiceHumano(humano), humano, angel, angelEnviado);
}

string Cielo::crearArchivoBitacora(){
    ofstream archivo;
    string nombre="Salvados_"+obtenerFechaYHoraActual()+".txt";
	archivo.open(nombre,ios::out); 
	if (archivo.fail()){
		cout<<"No escribí el archivo"<<endl;//que sad
		exit(1);
	}
    NodoBitacora * tmp= bitacora->primerNodo;
    while (tmp!=NULL){
        archivo<<"\n"<<tmp->fechayHora<<"\tHumano: "<<tmp->indice<<"\t"<<tmp->nombreYApellido<<"\t"<<tmp->pais<<endl;
	    archivo<<"Salvada el "<<tmp->fechayHora<<" por "<<tmp->pecado->cantidad<<" pecados."<<endl;
        archivo<<"Salva por el angel San"<<tmp->demonio<<"\tGeneración "<<tmp->angel->generacion<<endl;
        tmp=tmp->siguiente;
    }
	archivo.close();
    bitacora->primerNodo=bitacora->ultimoNodo=NULL; 
    return nombre;
} 

void Cielo::tenerPiedad(){
    Humano * humanoSalvado=infierno->sacarHumanoMasPecador();
    NodoCelestial * angel=arbolAngelical->salvarHumano(arbolAngelical->raiz, humanoSalvado); //No está probada esta función
    humanoSalvado->angelQueLoSalvo=angel;
    insertarEnTablaHash(humanoSalvado);
    generarBitacoraSalvacion(humanoSalvado, angel->nombreAngel+"("+to_string(angel->version)+")", angel);
}

string Cielo::salvacionGeneral(){
    arbolAngelical->generarNuevoNivel(arbolAngelical->raiz);
    int cantidadAngeles=arbolAngelical->contarHojas(arbolAngelical->raiz);
    for (int i=0; i < cantidadAngeles; i++){
        tenerPiedad();
    }
    return crearArchivoBitacora();
}

int Cielo::contarCantidadSalvados(){
    int cantidadDeNodos=0;
    for (int i=0; i<1000;i++){
        cantidadDeNodos+=tablaSacra[i]->contarNodos(r);
    }
    return cantidadDeNodos;
}

void Cielo::generarConsultaCelestial(){
    ofstream archivo;
    archivo.open("ConsultaCelestial.txt",ios::out);
    archivo<<"---------------------------- CIELO --------------------------------"<<endl;
    archivo<<"\nTotal actual de humanos residentes en el Cielo:\t"<<contarCantidadSalvados()<<"\n"<<endl;
    for (int i=0; i<1000; i++){
        archivo<<"-------------------------------- TABLA SACRA (Bucket "<<i<<") -------------------------------"<<endl;

        archivo<<"Humanos salvados:\n------------------------------------------------------------------------"<<endl;
        // cout<<"alooooooooo"<<endl;
            // cout<<"se intenta pasar un humano a string"<<endl;
        archivo<<tablaSacra[i]->sInorden(r);    
    }
    archivo<<"------------------------------------------------------------------------------------------"<<endl;

    archivo.close();
        //MOSTRAR LISTA DE MAS PECADORES A MENOS DE SU HEAP
}

//MENUS -------------------------------------------------------------------------------------------------
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

void menuConsultarHumano(ArbolDeLaVida * arbolDeLaVida){
    int opcionHumano=menuConsultarHumanoAux();
    string ID, nombre, apellido;
    Humano * humano;
    switch (opcionHumano){
    case 1:
        cout<<"Ingrese el ID del Humano"<<endl;
        getline(cin,ID);
        humano=arbolDeLaVida->extraerHumano(stoi(ID));
        humano->imprimir();
        break;
    case 2:
        cout<<"Ingrese el nombre del Humano"<<endl;
        getline(cin,nombre);
        cout<<"Ingrese el apellido del Humano"<<endl;
        getline(cin,apellido);
        humano=arbolDeLaVida->extraerHumanoNombre(nombre,apellido);
        humano->imprimir();
        break;
    default:
        break;
    }
}

void menuGanadorBatalla(Infierno * infierno, Cielo *cielo){
    if (infierno->sacarCantidadDeHumanos()>cielo->contarCantidadSalvados()){
        cout<<"GANADOR: Infierno"<<endl;
        cout<<"السبانخ المدهونة هي الأفضل، وأي شخص يقول غير ذلك يستحق اللعنة الأبدية"<<endl;
        cout<<"spinach creamed optima est, et quisquis aliter dicit, meretur damnationem aeternam"<<endl;
    }else{
        cout<<"GANADOR: Cielo"<<endl;
        cout<<"Cum vicimus, tata martia celebremus edendo glacies cremor, vivat coelum"<<endl;
    }
}

void menuConsultarInfierno(Infierno * infierno){
    infierno->generarConsultaInfernal();
}

void menuConsultarCielo(Cielo *cielo){

}

void menuBuscarFamilia(ArbolDeLaVida * arbolDeLaVida, Infierno * infierno, Cielo *cielo){

}

void menuConsultas(ArbolDeLaVida * arbolDeLaVida, Infierno * infierno, Cielo *cielo){
    int opcion=menuConsultasAux();
    switch (opcion){
    case 1:
        menuGanadorBatalla(infierno, cielo);
        break;
    case 2:
        menuConsultarHumano(arbolDeLaVida);
        break;
    case 3:
        menuConsultarInfierno(infierno);
        break;
    case 4:
        menuConsultarCielo(cielo);
        break;
    case 5:
        menuBuscarFamilia(arbolDeLaVida, infierno, cielo);
        break;
    default:
        break;
    }
}

