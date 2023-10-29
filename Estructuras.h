#include "iostream"
using namespace std;

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

struct Humano{

} ;

struct BitacoraCondenacion{

};

struct ListaDoble {
	NodoArticulo * primerArticulo, * ultimoArticulo;
	
    ListaDoble(){
		primerArticulo=ultimoArticulo=NULL;
    }

    void insertarInicio(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
    void insertarFinal (int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
	NodoArticulo * borrarAlFinal();
    void leerArchivoArticulos();
    void imprimir();
    bool encontrarArticulo(string _codigo);
    void actualizarArchivoArticulos();
    int revisarListaArticulos();
    int largo();
    bool encontrarArticuloRepetido(string _codigo);
    int cantidadArticuloBodega(string _codigo);
    int sacarTiempoFabricacion(string _codigo);
    void apartarProductos(ListaProductos *listaProductos);
    void annadirProductoAlmacen(int cantProducto, string codigoProducto);

        //Destructor
    ~ListaDoble() {
        NodoArticulo* tmp = primerArticulo;
        while (tmp) {
            NodoArticulo* siguiente = tmp->siguiente;
            delete tmp;
            tmp = siguiente;
        }
    }
    string encontrarUbicacionArticulo(string _codigo);
};