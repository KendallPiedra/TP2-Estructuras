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
//AMIGOS
struct ListaDoble {
	Nodo * primerNodo, * ultimoNodo;
	
    ListaDoble(){
		primerNodo=ultimoNodo=NULL;
    }

    void insertarInicio(int numero);
    void insertarFinal (int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
	Nodo * borrarAlFinal();
    void imprimir();
    int largo();

};

//HUMANOS

struct Humano{
    int ID;
    string nombre, apellido, pais, creencia, profesion, nacimieto;
    int redesSociales[7]; 
    ListaDoble * pecados;
    //0:Lujuria  
    //1:Gula
    //2:Avaricia
    //3:Pereza
    //4:Ira
    //5:Envidia
    //6:Soverbia 
    ListaDoble * amigos;
    bool vivo;

    Humano(int _ID, string _nombre, string _apellido, string _pais, string _creencia, string _profesion, string _nacimiento){
        ID=_ID;
        nombre=_nombre;
        apellido=_apellido;
        pais=_pais;
        creencia=_creencia;
        profesion=_profesion;
        nacimieto=_nacimiento;
        pecados= new ListaDoble();
        amigos= new ListaDoble();
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


struct ArbolDeLaVida{
    NodoArbol* raiz;
    
    ArbolDeLaVida (){
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





