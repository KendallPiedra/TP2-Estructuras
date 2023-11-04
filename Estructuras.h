#include <iostream>
using namespace std;

struct Humano;
//ANTIGUO NODO MÍSTICO
struct Pecado{
    int cantidad;
    string nombrePecado;
    Pecado(){
        cantidad=0;
    } 
};

//NODO RED SOCIAL
struct RedSocial{
    int gusto;
    string nombreRedSocial;
    RedSocial(){
        gusto=0;
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
    void imprimir();
};

//HUMANOS

struct Humano{
    int ID, cantidadAmigos;
    string nombre, apellido, pais, creencia, profesion, nacimieto;
    RedSocial * redesSociales[7]; 
    Pecado * pecados[7];
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
        vivo= true;
    }
    Humano(){

    }

    void agregarAmigos(Humano * arrayDeLaVida[], int cantHumanosActual);
    void inicializarPecados();
    void inicializarRedesSociales();
    void agregarPecado(string pecado, int cantidadAgregar);
    void imprimir();
    void publicarEnRedSocial(string redSocial, string pecado);
    void publicarEnVariasRedesSociales(int num);
    void ordenarRedesSociales();
    int determinarCantidadASumar(string redSocial);
};


//ARBOL
struct NodoArbol{
    Humano *humano;
    NodoArbol *hijoizquierdo, *hijoderecho;
       
    NodoArbol (Humano * _humano){
        humano=_humano;
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
        cantidadHumanos=0;      
    }
    
    void insertar (Humano * humano);
    NodoArbol * insertar (Humano * humano, NodoArbol*);
    //void insertar (int);
    //Nodo* insertar(int, Nodo*);
    int extraerIndiceHumano(Humano * humano);
    void inOrden(NodoArbol*);
    NodoArbol* buscar (int, NodoArbol*);
    NodoArbol* mayor (NodoArbol* arbol);
    int altura(NodoArbol*);
    int contadorNodos(NodoArbol*);
    bool validarID(int ID);
    void generarAmigosYPecados();
    void crearGeneracionHumanos(int cantidadAGenerar);
    int extraerCantidadNodos();
    void construirArbol(NodoArbol* raiz, int inicio, int fin, int cantidadDeseada, int contador);
    void ordenarArrayDeLaVida();
    void enviarAPecar(int ID, string redSocial, string pecado);
    void imprimir();
};

//BITACORA
struct BitacoraCondenacion{

};



//INFIERNO
struct Familia{
    string apellido, pais; 
    int cantMiembrosMax, cantMiembrosActual;
    Humano** familiares;
    Familia(string _apellido, string _pais, ArbolDeLaVida * ADLV){
        apellido= _apellido;
        pais=_pais;
        cantMiembrosMax=determinarCantMiembros(ADLV);
        familiares= new Humano*[cantMiembrosMax];
        cantMiembrosActual=0;
    } 
    int determinarCantMiembros(ArbolDeLaVida * arbolDeLaVida);
    void annadirFamiliar(Humano * familiar);
};
struct Demonio{
    Familia* familias[30*20];
    int cantFamilias;
    string nombre, pecado;
    Demonio(string _nombre,string _pecado){
        cantFamilias=0;
        nombre=_nombre;
        pecado=_pecado;
    }
    void matarHumano(Humano *humano);
};

struct Infierno{
    Demonio* demonios[7];//[cant demonios][cant familias][heap]
    Infierno() {
        string nombres[]={"Lucifer","Belcebú","Satán","Abadón","Mammón","Belfegor","Asmodeo"};
        string pecados[] = {"Orgullo", "Envidia", "Ira", "Pereza", "Codicia", "Gula", "Lujuria"}; //usemos "Gula" por que glotoneria esta muy feo
        for (int i =0; i<7;i++){
            demonios[i]=new Demonio(nombres[i],pecados[i]);
        }
    }
};