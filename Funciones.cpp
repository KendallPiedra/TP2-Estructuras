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

//MENUS -------------------------------------------------------------------------------------------------
int menuPrincipal(){
    string opcion;
    do{
        cout<<"------------------------------- MENÚ -------------------------------"<<endl;
	    cout<<"1: Agregar Pedido"<<endl;
	    cout<<"2: Apagar/Encender Balanceador"<<endl;
	    cout<<"3: Agregar Cliente"<<endl;
	    cout<<"4: Modificar Alistadores"<<endl;
	    cout<<"5: Modificar Robots Fabricadores"<<endl;
	    cout<<"6: Apagar/Encender Empacador"<<endl;
	    cout<<"7: Apagar/Encender Facturador"<<endl;
	    cout<<"8: Apagar/Encender Picking"<<endl;	
	    cout<<"9: Imprimir Colas"<<endl;
	    cout<<"0: Terminar la simulación"<<endl;
	    getline(cin,opcion);//validaciones varias
    } while (!esInt(opcion));
	return stoi(opcion);
}




