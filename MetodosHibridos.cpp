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

int Humano::sacarIndicePecado(string pecado){//UrgenterevisarStandartNombre
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

    int cantidadPecadores = PorcentajeACantidad(5, cantidadHumanos);
    Humano** HumanosPecadores = new Humano*[cantidadPecadores];
    int j=0;
    for (int i = 0; i < cantidadPecadores; i++) {
        
        bool annadio=false;
        while(annadio==false){
            if(arrayDeLaVida[indices[i]]->vivo){
                //esta vivo
                HumanosPecadores[i] = arrayDeLaVida[indices[j]];
                annadio=true;
                j++;
            } else{  j++;}//no esta vivo. Debe intentarlo con el siguiente
              
        }
        
    }
    
    return HumanosPecadores;
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
//INFIERNO

void Infierno::enviarDemonio(int posicionD){
    string pecado= demonios[posicionD]->pecado;
    Humano** condenados =ADLV->sacarPorcentajeMasPecador(pecado);
    int cantidadCondenados = PorcentajeACantidad(5, ADLV->cantidadHumanos);
    for (int i=0; i<cantidadCondenados;i++){
        if (condenados[i] == nullptr) {
            // No quedan condenados
            break;
        }
        demonios[posicionD]->matarHumano(condenados[i],ADLV);
    }
    
} 

void Infierno::realizarCondenacionGeneral(){
    for (int i; i<7;i++){
        enviarDemonio(i);
    }
}

void Infierno::consultaDeLosMiembrosDelInfierno(){
    for (int i=0; i<7; i++){
        cout<<demonios[i]->nombre<<"\nPecado: "<<demonios[i]->pecado<<endl;
        cout<<"Cantidad de humanos condenados: "<<demonios[i]->calcularCantidadHumanos()<<endl;
        cout<<"Promedio de pecados: "<<demonios[i]->calcularPromedioPecados()<<endl;
        cout<<"Maximo de pecados:"<<demonios[i]->calcularMaximoPecados()<<endl;
        cout<<"Minimo de pecados:"<<demonios[i]->calcularMinimoPecados()<<endl;

        //MOSTRAR LISTA DE MAS PECADORES A MENOS DE SU HEAP
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
    //falta validar que el bro esté vivop9k8
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


