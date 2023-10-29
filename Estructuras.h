#include "iostream"
using namespace std;

//NODO MISTICO
struct Nodo{
    Nodo*siguiente;
    Nodo*anterior;
    int numero;
    Nodo(int _numero){
        numero= _numero;
        siguiente=anterior=NULL;
    } 
};
//PECADITOS
struct ListaPecados{
    Nodo * primerPecado, * ultimoPecado;

    ListaPecados(){
        primerPecado=ultimoPecado=NULL;
    }
};
//AMIGOS
struct ListaAmigos {
	Nodo * primerHumano, * ultimoHumano;
	
    ListaAmigos(){
		primerHumano=ultimoHumano=NULL;
    }

    void insertarInicio(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
    void insertarFinal (int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
	Nodo * borrarAlFinal();
    void imprimir();
    bool encontrarHumano(string _codigo);
    int largo();

    string encontrarUbicacionArticulo(string _codigo);
};

//HUMANOS

struct Humano{
    int ID;
    string nombre, apellido, pais, creencia, profesion, nacimieto;
    int redesSociales[7]; 
    ListaPecados * pecados;
    //0:Lujuria  
    //1:Gula
    //2:Avaricia
    //3:Pereza
    //4:Ira
    //5:Envidia
    //6:Soverbia 
    ListaAmigos * amigos;
    bool vivo;

    Humano(int _ID, string _nombre, string _apellido, string _pais, string _creencia, string _profesion, string _nacimiento){
        ID=_ID;
        nombre=_nombre;
        apellido=_apellido;
        pais=_pais;
        creencia=_creencia;
        profesion=_profesion;
        nacimieto=_nacimiento;
        pecados= new ListaPecados();
        amigos= new ListaAmigos();
    }
} ;


//ARBOL
struct NodoArbol{
    int dato;
    NodoArbol* hijoizquierdo;
    NodoArbol* hijoderecho;
       
    NodoArbol (int d){
        dato = d;
        hijoizquierdo = hijoderecho = NULL;    
    }          

    void imprimir();
};


struct Arbol{
    NodoArbol* raiz;
    
    Arbol (){
        raiz = NULL;      
    }
    
    void insertar (int);
    NodoArbol * insertar (int, NodoArbol*);
    //void insertar (int);
    //Nodo* insertar(int, Nodo*);
    void inOrden(NodoArbol*);
    void inOrdenClientes(NodoArbol*);
    void preOrden(NodoArbol*);
    void posOrden(NodoArbol*);
    NodoArbol* buscar (int, NodoArbol*);
    int obtenerNumeroElementos(NodoArbol*);
    int peso (NodoArbol*);
    int obtenerAltura(NodoArbol*);
    NodoArbol* mayor (NodoArbol* arbol);
    NodoArbol* borrarElemento(int);
    NodoArbol* borrarElemento(int, NodoArbol*);
    void anchura(NodoArbol*);
    int altura(NodoArbol*);
    int cantHojas(NodoArbol*);
    int cantNodos2(NodoArbol*);
    void nodos_nivel (NodoArbol*, int, int);
    int contadorNodos(NodoArbol*);
};

//BITACORA
struct BitacoraCondenacion{

};





