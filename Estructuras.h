#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Humano;

struct Pecado{
    int cantidad;
    string nombrePecado;
    Pecado(string _nombrePecado){
        nombrePecado=_nombrePecado;
        cantidad=0;
    } 
};

//NODO RED SOCIAL
struct RedSocial{
    int gusto;
    string nombreRedSocial;
    RedSocial(string _nombreRedSocial, int _gusto){
        gusto=_gusto;
        nombreRedSocial=_nombreRedSocial;
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
    //0:Orgullo  
    //1:Envidia
    //2:Ira
    //3:Pereza
    //4:Codicia
    //5:Gula
    //6:Lujuria 
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
        
        // string sPecados[] = {"Orgullo", "Envidia", "Ira", "Pereza", "Codicia", "Gula", "Lujuria"}; //usemos "Gula" por que glotoneria esta muy feo
        // string sPecados[] = {"Orgullo", "Envidia", "Ira", "Pereza", "Codicia", "Gula", "Lujuria"};
        // for (int i=0; i<7){
        //     pecados[i]= new Pecado(sPecados[i]);
            //Falta añadir REDES SOCIALES
        // }
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
    int sacarIndicePecado(string pecado);

    
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
    int construirArbol(int inicio, int fin, int cantidadDeseada, int contador);
    void ordenarArrayDeLaVida();
    void enviarAPecar(int ID, string redSocial, string pecado);
    void imprimir();
    int sacarIndicePecado(string pecado);
    Humano** sacarPorcentajeMasPecador(string pecado);
    vector<int> sacarIndicesOrdenadosSegunPecado(string pecado);

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
    void insertarEnFamiliaNueva(Humano*humano, ArbolDeLaVida * ADLV);
    void matarHumano(Humano *humano, ArbolDeLaVida * ADLV);
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
    void enviarDemonio(int posicionD, ArbolDeLaVida *ADLV);

    void realizarCondenacion(ArbolDeLaVida *ADLV);
    
};