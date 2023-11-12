#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream> 
using namespace std;

#include<cstdio>
#include<sstream>

//PECADO --------------------------------------------------------------------------------------------------------


struct Humano{
    int ID;
    string nombre;
    //0:Lujuria  
    //1:Gula
    //2:Avaricia
    //3:Pereza
    //4:Ira
    //5:Envidia
    //6:Soverbia  
    bool vivo;

    Humano(int _ID, string _nombre){
        ID=_ID;
        nombre=_nombre;

    }

};


//ARBOL ----------------------------------------------------------------------------------------------------------------
struct NodoArbol{
    Humano *humano;
    NodoArbol *hijoizquierdo, *hijoderecho;
       
    NodoArbol (Humano * _humano){
        humano=_humano;
        hijoizquierdo = hijoderecho = NULL;    
    }          

    void imprimir();
};

struct ArbolAVL{
    NodoArbol* raiz;
    int cantidadHumanos;
    ArbolAVL (){
        raiz = NULL;
        cantidadHumanos=0;      
    }
    
    void insertar (Humano * humano);
    NodoArbol * insertar (Humano * humano, NodoArbol*);
    void inOrden(NodoArbol*);
    int altura(NodoArbol*);
    int contadorNodos(NodoArbol*);
    int extraerCantidadNodos();
    int construirArbol(int inicio, int fin, int cantidadDeseada, int contador);
    void imprimir();

};