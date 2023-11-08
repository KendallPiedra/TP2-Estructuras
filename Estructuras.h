#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream> 
using namespace std;

struct Humano;
string extraerDemonioConPecado(string pecado);

//PECADO --------------------------------------------------------------------------------------------------------
struct Pecado{
    int cantidad;
    string nombrePecado;
    Pecado(string _nombrePecado){
        nombrePecado=_nombrePecado;
        cantidad=0;
    } 
    Pecado(string _nombreRedSocial, int _gusto){ //redSocial
        nombrePecado=_nombreRedSocial;
        cantidad=_gusto;
    }
};

//NODO RED SOCIAL --------------------------------------------------------------------------------------------------------
struct RedSocial{
    int gusto;
    string nombreRedSocial;
    RedSocial(string _nombreRedSocial, int _gusto){
        gusto=_gusto;
        nombreRedSocial=_nombreRedSocial;
    } 
};

//AMIGOS ---------------------------------------------------------------------------------------------------------------
struct NodoAmigo{
    NodoAmigo *siguiente, *anterior;
    Humano *amigo;
    NodoAmigo(Humano *_amigo){
        amigo=_amigo;
        siguiente=anterior=NULL;
    } 
    void imprimir();
};

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
    void imprimirConPecados();
};

//HUMANOS --------------------------------------------------------------------------------------------------------------

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
        
        // string sPecados[] = {"Orgullo", "Envidia", "Ira", "Pereza", "Codicia", "Gula", "Lujuria"}; //usemos "Gula" por que glotoneria esta muy feo
        // string sPecados[] = {"Orgullo", "Envidia", "Ira", "Pereza", "Codicia", "Gula", "Lujuria"};
        // for (int i=0; i<7){
        //     pecados[i]= new Pecado(sPecados[i]);
            //Falta añadir REDES SOCIALES
        // }
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
    int sacarCantidadPecado(string pecado);
    string convertirAString();

    void imprimirPecados();
    void imprimirRedesSociales();
    
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
    void generarAmigos();
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

//BITACORA -----------------------------------------------------------------------------------------------------------------
struct NodoBitacora{
    int indice;
    string fechayHora, nombreYApellido, pais, demonio;
    Pecado * pecado;
    NodoBitacora *siguiente, *anterior;

    NodoBitacora(int _indice, Humano *humano, string _pecado, string _fechayHora){
        indice=_indice;
        fechayHora=_fechayHora;
        nombreYApellido=humano->nombre+" "+humano->apellido;
        pais=humano->pais;
        demonio=extraerDemonioConPecado(_pecado);
        pecado= new Pecado(_pecado,humano->sacarCantidadPecado(_pecado));
        siguiente=anterior=NULL;
    } 

    ~NodoBitacora() {
        delete pecado, siguiente, anterior; 
    }
};

struct BitacoraCondenacion{
    NodoBitacora * primerNodo, * ultimoNodo;
	
    BitacoraCondenacion(){
		primerNodo=ultimoNodo=NULL;
    }

    void insertarFinal (int indice, Humano * humano, string pecado);
};

//INFIERNO -----------------------------------------------------------------------------------------------------------------
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
    int calcularCantidadHumanos();
    int calcularMaximoPecados();
    int calcularMinimoPecados();
    int calcularPromedioPecados();
    Humano** sacarListaDeHumanos();
    Humano** sacarListaDeLosMasPecadores();
};

struct Infierno{
    Demonio* demonios[7];//[cant demonios][cant familias][heap]
    ArbolDeLaVida * ADLV;
    BitacoraCondenacion * bitacora;
    Infierno() {
        string nombres[]={"Asmodeo","Belfegor","Mammón","Abadón","Satán","Belcebú","Lucifer"};
        string pecados[] = {"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"}; 
        for (int i =0; i<7;i++){
            demonios[i]=new Demonio(nombres[i],pecados[i]);
        }
        bitacora=new BitacoraCondenacion();
    }
    void enviarDemonio(int posicionD);
    void realizarCondenacionGeneral();
    void consultaDeLosMiembrosDelInfierno();
    void generarBitacoraCondenacion(Humano * humano, string pecado); 
    void crearArchivoBitacora(); //Al final hay que vaciar la bitácora para volver a llenarla en otra condenación
    void enviarCorreo(); //AHHHHHHHHHHHH
};