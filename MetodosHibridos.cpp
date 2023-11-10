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
    cout<<"Se llama a sacar cantidad de pecado"<<endl;
    cout<<pecado<<endl;
    int iPecado=sacarIndicePecado(pecado);
    cout<<"iPecado:"<<iPecado<<endl;
    cout<<"cantidad:"<<pecados[iPecado]->cantidad<<endl;

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
        cin.get();
        cout<<"i: "<<i<<endl;
        cout<<"j: "<<j<<endl;
        cin.get();
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
void Familia::annadirFamiliar(Humano * familiar){
        familiares[cantMiembrosActual]=familiar;
        cantMiembrosActual++;
    }

//DEMONIOS ------------------------------------------------------------------------------------------------------------

void Demonio::insertarEnFamiliaNueva(Humano*humano, ArbolDeLaVida * ADLV){
    familias[cantFamilias]=new Familia(humano->apellido,humano->pais, ADLV);
    familias[cantFamilias]->annadirFamiliar(humano);
    cantFamilias++;
}

void Demonio::matarHumano(Humano *humano, ArbolDeLaVida * ADLV){
    humano->vivo=false;
    Familia *fam;
    for (int i=0; i<cantFamilias;i++){
        fam= familias[i];
        if (humano->pais==fam->pais  &&humano->apellido==fam->apellido
        ){
            fam->annadirFamiliar(humano);
        }
    }
    insertarEnFamiliaNueva(humano, ADLV);
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
    cout << "Entra a la funcion sacarListaDeLosMasPecadores" << endl;
    cin.get();

    Humano** listaHumanos = sacarListaDeHumanos();
    cout << "Se logra sacar la lista de humanos" << endl;
    cin.get();

    int cantidad = calcularCantidadHumanos();
    cout << "Cantidad de humanos: " << cantidad << endl;
    cin.get();

    for (int i = 0; i < cantidad-1; i++) {
        int maxIdx = i;
        for (int j = i+1; j < cantidad; j++) {
            cout<<"I:"<<i<<endl;
            cout<<"J:"<<j<<endl;
            cin.get();
            cout<<pecado<<endl;
            cout<<listaHumanos[j]->sacarCantidadPecado(pecado)<<endl; 
            cout<<listaHumanos[maxIdx]->sacarCantidadPecado(pecado)<<endl;

            if (listaHumanos[j]->sacarCantidadPecado(pecado) > listaHumanos[maxIdx]->sacarCantidadPecado(pecado)){
                maxIdx = j;
            }
            cout<<maxIdx<<endl;
        }
        Humano * temp = listaHumanos[maxIdx];
        listaHumanos[maxIdx] = listaHumanos[i];
        listaHumanos[i] = temp;
    }

    cout << "Lista de los más pecadores ordenada correctamente" << endl;
    cin.get();

    return listaHumanos;
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

void Infierno::realizarCondenacionGeneral(){
    for (int i; i<7;i++){
        enviarDemonio(i);
        // cout<<"no"<<endl;
    }
    string nombre=crearArchivoBitacora();
    // system("enviarCorreo.exe krisncl1701@gmail.com OneDrive\\Escritorio\\Homeworks\\2k23 II SEMESTRE\\Estructuras de Datos\\TP2-Estructuras\\nombres.txt");
    // cout<<"realizar"<<endl;
}

void Infierno::consultaDeLosMiembrosDelInfierno(){
    cout<<"se abre el archivo"<<endl;
    ofstream archivo;
    archivo.open("ConsultaInfernal.txt",ios::out);
    cout<<"se abrió el archivo"<<endl;
    for (int i=0; i<7; i++){
        archivo<<demonios[i]->nombre<<"\nPecado: "<<demonios[i]->pecado<<endl;
        archivo<<"Cantidad de humanos condenados: "<<demonios[i]->calcularCantidadHumanos()<<endl;
        archivo<<"Promedio de pecados: "<<demonios[i]->calcularPromedioPecados()<<endl;
        archivo<<"Maximo de pecados:"<<demonios[i]->calcularMaximoPecados()<<endl;
        archivo<<"Minimo de pecados:"<<demonios[i]->calcularMinimoPecados()<<endl;
        cout<<"se pusieron los datos del demonio"<<endl;
        std::cin.get(); // Espera que el usuario presione Enter

        cout<<"se calculan los humanos"<<endl;
        
        int cantidadHumanos = demonios[i]->calcularCantidadHumanos();
        cout<<"sacar lista de los mas pecadores"<<endl;
        std::cin.get(); // Espera que el usuario presione Enter

        Humano**listaOrdenadaHumanos=demonios[i]->sacarListaDeLosMasPecadores();
        cout<<"se saco la lista de los mas pecadores"<<endl;
        cin.get();
        archivo<<"Humanos Condenados:\n------------------------------------------------------------------------"<<endl;
        cout<<"alooooooooo"<<endl;
        cin.get();
        for (int j=0; j< cantidadHumanos;j++){
            cout<<"se intenta pasar un humano a string"<<endl;

            archivo<<listaOrdenadaHumanos[j]->convertirAString()<<endl;
            archivo<<"------------------------------------------------------------------------------------------"<<endl;
        }
    }
    archivo.close();
        //MOSTRAR LISTA DE MAS PECADORES A MENOS DE SU HEAP
}


//ARBOL CELESTIAL --------------------------------------------------------------------------------------
void ArbolAngelical::invocarAngeles(){
    string nombresAngelicales[]={"Miguel","Nuriel","Aniel","Rafael","Gabriel","Shamsiel","Raguel", "Uriel", "Azrael", "Sariel"};
    generarNuevoNivel(raiz);
    for (int i = 0; i < 10; i++){
        generarVersiones(raiz,nombresAngelicales[i]);
        numeroVersion=0;
    }
}

//MENUS -------------------------------------------------------------------------------------------------

void ArbolDeLaVida::enviarAPecar(int ID, string redSocial, string pecado){
    for (int i=0; i < cantidadHumanos; i++){
        if(arrayDeLaVida[i]->ID==ID && arrayDeLaVida[i]->vivo){
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


