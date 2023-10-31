#include <iostream>
using namespace std;

//ANTIGUO NODO MÍSTICO
struct Pecado{
    int cantidad;
    string nombrePecado;
    Pecado(){
        cantidad=0;
    } 
};

//NODO AMIGOS
struct NodoAmigo{
    NodoAmigo *siguiente, *anterior;
    Humano *amigo;
    NodoAmigo(Humano *_amigo){
        amigo=_amigo;
        siguiente=anterior=NULL;
    } 
    void imprimir();
};

//AMIGOS
struct ListaBesties {
	NodoAmigo * primerNodo, * ultimoNodo;
	
    ListaBesties(){
		primerNodo=ultimoNodo=NULL;
    }

    void insertarInicio(Humano *amigo);
    void insertarFinal (Humano *amigo);
	NodoAmigo * borrarAlFinal();
    int largo();
    bool tieneAmigo(int ID);
};

//HUMANOS

struct Humano{
    int ID, cantidadAmigos;
    string nombre, apellido, pais, creencia, profesion, nacimieto;
    int redesSociales[7]; 
    Pecado pecados[7];
    //0:Lujuria  
    //1:Gula
    //2:Avaricia
    //3:Pereza
    //4:Ira
    //5:Envidia
    //6:Soverbia 
    ListaBesties * amigos;
    bool vivo;

    Humano(int _ID, string _nombre, string _apellido, string _pais, string _creencia,
    string _profesion, string _nacimiento, int _cantAmigos){
        ID=_ID;
        nombre=_nombre;
        apellido=_apellido;
        pais=_pais;
        creencia=_creencia;
        profesion=_profesion;
        nacimieto=_nacimiento;
        cantidadAmigos=_cantAmigos;
        amigos= new ListaBesties();
    }

    void agregarAmigos(Humano * arrayDeLaVida[], int cantHumanosActual);
    void inicializarPecados();
    void agregarPecado(string pecado);
};


//ARBOL
struct NodoArbol{
    Humano *humano;
    NodoArbol *hijoizquierdo, *hijoderecho;
       
    NodoArbol (Humano * _humano){

        hijoizquierdo = hijoderecho = NULL;    
    }          

    void imprimir();
};


struct ArbolDeLaVida{
    NodoArbol* raiz;
    Humano * arrayDeLaVida[100000];
    int cantidadHumanos;
    ArbolDeLaVida (){
        raiz = NULL;      
    }
    
    void insertar (Humano * humano);
    NodoArbol * insertar (Humano * humano, NodoArbol*);
    //void insertar (int);
    //Nodo* insertar(int, Nodo*);
    void inOrden(NodoArbol*);
    NodoArbol* buscar (int, NodoArbol*);
    NodoArbol* mayor (NodoArbol* arbol);
    int altura(NodoArbol*);
    int definirPunteroHojas(NodoArbol*);
    int contadorNodos(NodoArbol*);
    bool validarID(int ID);
    void generarAmigosYPecados();
    void crearGeneracionHumanos(int cantidadAGenerar);
    int extraerCantidadNodos();
    void construirArbol(NodoArbol* raiz, int inicio, int fin, int cantidadDeseada, int contador);
};

//BITACORA
struct BitacoraCondenacion{

};





