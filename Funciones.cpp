#include "iostream"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int maximo (int a, int b){
    if (a>b)
       return a;
    else return b;    
}

int generarNumerosAleatorios(int tope) {
    return rand() % tope + 1;
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

void generarRedesSocialesFavoritas(int redesSociales[]){
    for (int i = 0; i < 7; i++){
        
    }
        
}

