#include <iostream>
#include <cstdlib>
// #include <ctime>
#include <fstream>
// #include <sstream>
#include <string>
#include <chrono>
using namespace std;

//VALIDACIONES ----------------------------------------------------------------------------------------
bool esPotenciaDeDos(int numero) {
    return (numero > 0) && ((numero & (numero - 1)) == 0);
}

bool esInt(string numero) {
    for (char c : numero) {
        if (!isdigit(c)) 
            return false;
	}
	return true;
}

//FUNCIONES REUTILIZABLES -----------------------------------------------------------------------------
int maximo (int a, int b){
    if (a>b)
       return a;
    else return b;    
}

int generarNumerosAleatorios(int tope) {
    return rand() % tope + 1;
}

int calcularPorcentaje(int cantidad) {
    return cantidad / 100;
}

int extraerElementoCentral(int longitud) {
    return (longitud - 1) / 2;
}

string extraerLineaAleatoria(string nombreArchivo, int cantLineasArchivo){
    //Extrae una linea random del archivo que se ocupe, en este caso, paises, nombres, apellidos, etc.
    //Importante ingresar el tope correcto o se puede caer
    //Nombres 1000, Apellidos 30, Paises 20, Profesiones 20, Creencias 10
    string texto=" ";
    int linea=generarNumerosAleatorios(cantLineasArchivo); 
    ifstream archivo;
	archivo.open(nombreArchivo,ios::in);
	if (archivo.fail()){
		cout<<"No lei el archivo"<<endl;
		exit(1);
	}else{
		for (int i = 0; i < linea; i++){
            getline(archivo, texto);
        }
		archivo.close();
	}
    return texto;
}

//Fecha y Hora -----------
string obtenerHoraActual() {
    auto ahora = chrono::system_clock::now();
    time_t tiempoActual = chrono::system_clock::to_time_t(ahora);
    tm tiempoLocal = *localtime(&tiempoActual);
    char buffer[9];
    sprintf(buffer, "%02d-%02d-%02d", tiempoLocal.tm_hour,
	 tiempoLocal.tm_min, tiempoLocal.tm_sec);
    return string(buffer);
}

string obtenerFechaActual() {
    auto ahora = chrono::system_clock::now();
    time_t tiempoActual = chrono::system_clock::to_time_t(ahora);
    tm tiempoLocal = *localtime(&tiempoActual);
    char buffer[11];
    sprintf(buffer, "%02d-%02d-%04d", tiempoLocal.tm_mday,
	 tiempoLocal.tm_mon + 1, tiempoLocal.tm_year + 1900);
    return string(buffer);
}

string obtenerFechaYHoraActual() {
    string fecha = obtenerFechaActual();
    string hora = obtenerHoraActual();
    return fecha + "_" + hora;
}

//FUNCIONES PROPIAS DE LA PROGRA ------------------------------------------------------------------------
void generarRedesSocialesFavoritas(int redesSociales[]){
    for (int i = 0; i < 7; i++){
        redesSociales[i]=generarNumerosAleatorios(100);
    }
}

string extraerPecadoConRedSocial(string redSocial){
    // string nombresRedes[]={"Tinder", "iFood", "LinkedIn", "Netflix", "Twitter", "Facebook", "Instagram"};
    // string pecadosCapitales[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    if(redSocial=="Tinder")
        return "Lujuria";
    else if(redSocial=="iFood")
        return "Gula";
    else if(redSocial=="LinkedIn")
        return "Avaricia";
    else if(redSocial=="Netflix")
        return "Pereza";
    else if(redSocial=="Twitter")
        return "Ira";
    else if(redSocial=="Facebook")
        return "Envidia";
    else if(redSocial=="Instagram")
        return "Soberbia";
    return "AYYY";
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

int seleccionarRedSocial(){
    string redSocial;
    cout<<"------------------------------- REDES SOCIALES -------------------------------"<<endl;
    cout<<"1: Tinder"<<endl;
	cout<<"2: iFood"<<endl;
	cout<<"3: LinkedIn"<<endl;
	cout<<"4: Netflix"<<endl;
	cout<<"5: Twitter"<<endl;
	cout<<"6: Facebook"<<endl;
	cout<<"7: Instagram"<<endl;
	cout<<"Selecione la red Social: "<<endl;
    getline(cin,redSocial); //validaciones
    return stoi(redSocial);
}

string seleccionarReligion(){
    string religion;
	cout<<"Ingrese la religión que desea: "<<endl;
    getline(cin,religion); //validaciones
    return religion;
}

string seleccionarProfesion(){
    string profesion;
	cout<<"Ingrese la profesión que desea: "<<endl;
    getline(cin,profesion); //validaciones
    return profesion;
}

string seleccionarPais(){
    string pais;
	cout<<"Ingrese el país que desea: "<<endl;
    getline(cin,pais); //validaciones
    return pais;
}

string seleccionarApellido(){
    string apellido;
	cout<<"Ingrese el apellido que desea: "<<endl;
    getline(cin,apellido); //validaciones
    return apellido;
}