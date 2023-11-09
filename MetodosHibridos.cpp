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
    int iPecado=sacarIndicePecado(pecado);
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
    datos += "Cantidad Amigos: " + to_string(cantidadAmigos) + "\n";
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

vector<int> ArbolDeLaVida::sacarIndicesOrdenadosSegunPecado(string pecado){
    vector<int> indices(cantidadHumanos);
    for (int i=0;i<cantidadHumanos;i++){
        indices[i]=i;
    }
    int indicePecado=sacarIndicePecado(pecado);
    sort(indices.begin(), indices.end(), [this,indicePecado](int a, int b) {
    return arrayDeLaVida[a]->pecados[indicePecado] > arrayDeLaVida[b]->pecados[indicePecado];
    });
    return indices;

}

Humano** ArbolDeLaVida::sacarPorcentajeMasPecador(string pecado) {//PROBAR
    vector<int> indices = sacarIndicesOrdenadosSegunPecado(pecado);
    cout<<"se saca la cantidad de humanos a matar"<<endl; 
    int cantidadPecadores = PorcentajeACantidad(5, cantidadHumanos);
    cout<<"se sacó"<<endl;
    Humano** HumanosPecadores = new Humano*[cantidadPecadores];
    int j=0;
    for (int i = 0; i < cantidadPecadores; i++) {
        cout<<"i: "<<i<<endl;
        cout<<"j: "<<j<<endl;
        bool annadio=false;
        while(annadio==false){
            if(arrayDeLaVida[indices[i]]->vivo){
                //esta vivo
                cout<<"humano:"<<HumanosPecadores[i]->ID<<endl;
                HumanosPecadores[i] = arrayDeLaVida[indices[j]];
                annadio=true;
                j++;
            } else {j++;}//no esta vivo. Debe intentarlo con el siguiente  
        } 
    }
    return HumanosPecadores;
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
        if (humano->pais==fam->pais  &&humano->apellido==fam->pais){
            fam->annadirFamiliar(humano);
        }
    }
    insertarEnFamiliaNueva(humano, ADLV);
}

int Demonio::calcularCantidadHumanos(){
    int cantidad;
    for (int i=0; i<cantFamilias;i++){
        cantidad+=familias[i]->cantMiembrosActual;
    }
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
        }
    }
    return listaHumanos;
}

Humano ** Demonio::sacarListaDeLosMasPecadores(){
    Humano** listaHumanos=sacarListaDeHumanos();
    int cantidad = calcularCantidadHumanos();
    for (int i = 0; i < cantidad-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < cantidad; j++) {
            
            if (listaHumanos[j]->sacarCantidadPecado(pecado) < listaHumanos[minIdx]->sacarCantidadPecado(pecado)){
                minIdx = j;
            }
        }
        Humano * temp = listaHumanos[minIdx];
        listaHumanos[minIdx] = listaHumanos[i];
        listaHumanos[i] = temp;
    }
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

void Infierno::crearArchivoBitacora(){
    ofstream archivo;
	archivo.open(obtenerFechaYHoraActual(),ios::out); 
	if (archivo.fail()){
		cout<<"No escribí el archivo"<<endl;//que sad
		exit(1);
	}
    NodoBitacora * tmp= bitacora->primerNodo;
    while (tmp!=NULL){
        archivo<<tmp->fechayHora<<"\tHumano: "<<tmp->indice<<"\t"<<tmp->nombreYApellido<<"\t"<<tmp->pais<<endl;
	    archivo<<"Murió el "<<tmp->fechayHora<<endl;
        archivo<<"\tCondenado por "<<tmp->pecado->cantidad<<" pecados de "<<tmp->pecado->nombrePecado<<
        " por el demonio "<<tmp->demonio<<endl;
        archivo<<"\n"<<endl;
        tmp=tmp->siguiente;
    }
	archivo.close();
    bitacora->primerNodo=bitacora->ultimoNodo=NULL; 
} 

void Infierno::realizarCondenacionGeneral(){
    for (int i; i<7;i++){
        enviarDemonio(i);
        cout<<"no"<<endl;
    }
//crearArchivoBitacora();
cout<<"realizar"<<endl;
}

void Infierno::consultaDeLosMiembrosDelInfierno(){
    ofstream archivo;
    archivo.open("ConsultaInfernal.txt",ios::out);
    for (int i=0; i<7; i++){
        archivo<<demonios[i]->nombre<<"\nPecado: "<<demonios[i]->pecado<<endl;
        archivo<<"Cantidad de humanos condenados: "<<demonios[i]->calcularCantidadHumanos()<<endl;
        archivo<<"Promedio de pecados: "<<demonios[i]->calcularPromedioPecados()<<endl;
        archivo<<"Maximo de pecados:"<<demonios[i]->calcularMaximoPecados()<<endl;
        archivo<<"Minimo de pecados:"<<demonios[i]->calcularMinimoPecados()<<endl;

        int cantidadHumanos = demonios[i]->calcularCantidadHumanos();
        Humano**listaOrdenadaHumanos=demonios[i]->sacarListaDeLosMasPecadores();
        archivo<<"Humanos Condenados:\n------------------------------------------------------------------------"<<endl;
        for (int i=0; i< cantidadHumanos;i++){
            archivo<<listaOrdenadaHumanos[i]->convertirAString()<<endl;
            archivo<<"------------------------------------------------------------------------------------------"<<endl;
        }
    }
    archivo.close();
        //MOSTRAR LISTA DE MAS PECADORES A MENOS DE SU HEAP
}

//---------------------------------------------------------------------saflkdjsdlofjdegl
// string facturarPedido(NodoPedido *pedido, string _nombreArchivo){
// 	ofstream archivo;
// 	short contador=0;
// 	archivo.open(_nombreArchivo,ios::out); //Al ya existir lo va a sobreescribir
// 	if (archivo.fail()){
// 		cout<<"No escribí el archivo"<<endl;
// 		exit(1);
// 	}
// 	archivo<<"Pedido: \t"<<pedido->numeroPedido<<endl;
// 	archivo<<"Cliente: \t"<<pedido->codigoCliente<<endl;
// 	cout<<"Llegué aqui"<<endl;
// 	Movimiento * tmpMov=pedido->movimientos->primerMov;
// 	while (tmpMov!=NULL){
// 		if (!tmpMov->robot && !tmpMov->alistador){
// 			archivo<<tmpMov->ubicacion<<"\t"<<tmpMov->info<<endl;
// 		}
// 		tmpMov=tmpMov->siguiente;
// 	}
// 	cout<<"Otra vez"<<endl;
// 	tmpMov=pedido->movimientos->primerMov;
// 	while (tmpMov!=NULL){
// 		if(tmpMov->robot){ //robot
// 			archivo<<endl;
// 			archivo<<"Robots Fábrica"<<endl;
// 			archivo<<"ARTICULO " << tmpMov->articulo<< "\t Fabricado en "<< 
// 			tmpMov->fabricadoEn << "/n"<< tmpMov->cantidad<< "unidades"<<
// 			"\nincio: "<<tmpMov->fechaInicio <<"\nfinal: "<<tmpMov->fechaFinal<<endl;
// 		}else if (tmpMov->alistador){ //alistador
// 			if(contador==0){
// 				archivo<<endl;
// 				archivo<<"Alisto "<< "\t Alistador "<< tmpMov->numAlistador <<endl;
// 				contador++;
// 			}
// 			archivo<< tmpMov->articulo<< "\t Ubicación: "<<tmpMov->ubicacion <<
// 			"\tfinal: "<<tmpMov->tiempo<< "s" << endl;
// 		}
// 		tmpMov=tmpMov->siguiente;
// 	}
// 	cout<<"Aqui también llegué"<<endl;
// 	archivo.close();
// 	return "Listo";
// }

//---------------------------------------------------------------------saflkdjsdlofjdegl
   
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


