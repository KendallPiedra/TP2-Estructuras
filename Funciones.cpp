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





