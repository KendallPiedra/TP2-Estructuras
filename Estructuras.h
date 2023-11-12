#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream> 
using namespace std;

#include<cstdio>
#include<sstream>


struct Humano;
struct NodoCelestial;
struct Familia;
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
    string convertirAmigosAString();
};

//HUMANOS --------------------------------------------------------------------------------------------------------------
struct Humano{
    int ID, cantidadAmigos, totalPecados;
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
    bool salvado;
    NodoCelestial * angelQueLoSalvo;

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
        totalPecados=0;
        angelQueLoSalvo=NULL;
        salvado=NULL;
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
    int extraerPecadosTotales();
    void imprimirPecados();
    void imprimirRedesSociales();

    string convertirPecadosAString();
    string convertirRedesSocialesAString();
    string convertirAString();    
    string convertirAStringCelestial();
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
    Humano * extraerHumano(int ID);
    Humano * extraerHumanoNombre(string nombre, string apellido);
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
    int * sacarIndicesOrdenadosSegunPecado(string pecado);

    Familia * sacarFamiliaCompleta(string apellido, string pais);

};

//BITACORA -----------------------------------------------------------------------------------------------------------------
struct NodoBitacora{
    int indice;
    string fechayHora, nombreYApellido, pais, demonio;
    Pecado * pecado;
    NodoCelestial * angel;
    NodoBitacora *siguiente, *anterior;

    NodoBitacora(int _indice, Humano *humano, string _pecado, string _fechayHora, string _demonio, int cantidadPecado){
        indice=_indice;
        fechayHora=_fechayHora;
        nombreYApellido=humano->nombre+" "+humano->apellido;
        pais=humano->pais;
        demonio=_demonio;
        pecado= new Pecado(_pecado,cantidadPecado); //por si acaso
        siguiente=anterior=NULL;
        angel=NULL;
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
    void insertarFinalCielo(int indice, Humano * humano, string angel, NodoCelestial *angelEnviado);
};

//INFIERNO -----------------------------------------------------------------------------------------------------------------
struct Familia{
    string apellido, pais, pecado; 
    int cantMiembrosMax, cantMiembrosActual;
    Humano** familiares;
    Familia(string _apellido, string _pais,string _pecado,ArbolDeLaVida * ADLV){
        apellido= _apellido;
        pais=_pais;
        pecado=_pecado;
        cantMiembrosMax=determinarCantMiembros(ADLV)*10;
        familiares= new Humano*[cantMiembrosMax];
        cantMiembrosActual=0;
    } 
    int determinarCantMiembros(ArbolDeLaVida * arbolDeLaVida);
    void annadirFamiliar(Humano * familiar);
    void ordenarHeap(int k);
    void borrarRaiz();
    Humano* sacarRaiz();

    int buscarFamiliarPorID(int ID);
    int contarVivos();
    int contarCondenados();
    int contarSalvados();
    double sacarPorcentajeViVos();
    double sacarPorcentajeCielo();
    double sacarPorcentajeInfierno();
};

struct Demonio{
    Familia* familias[600];
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
    Humano* sacarHumano(int idxFamilia);
    Humano* mostrarHumanoRaiz(int idxFamilia);

    int buscarFamiliaDelAlmaCaptiva(int ID);
};

struct Infierno{
    Demonio* demonios[7];//[cant demonios][cant familias][heap]
    ArbolDeLaVida * ADLV;
    
    BitacoraCondenacion * bitacora;
    Infierno(ArbolDeLaVida*_ADLV) {
        ADLV=_ADLV;
        string nombres[]={"Asmodeo","Belfegor","Mammón","Abadón","Satán","Belcebú","Lucifer"};
        string pecados[] = {"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"}; 
        for (int i =0; i<7;i++){
            demonios[i]=new Demonio(nombres[i],pecados[i]);
        }
        bitacora=new BitacoraCondenacion();
    }
    void enviarDemonio(int posicionD);
    string realizarCondenacionGeneral();
    void generarConsultaInfernal();
    void generarBitacoraCondenacion(Humano * humano, string pecado); 
    string crearArchivoBitacora(); //Al final hay que vaciar la bitácora para volver a llenarla en otra condenación
    void enviarCorreo(); //AHHHHHHHHHHHH
    int sacarCantidadDeFamilias();
    int sacarCantidadDeHumanos();
    Humano * sacarHumano(int IDHumano);
    Humano ** sacarListaDeRaicesDemoniacas();
    int buscarHumanoMasPecador();
    Humano* sacarHumanoMasPecador();
    int buscarDemonioConAlmaCaptiva(int ID);//cambiar

};

// EL CIELO ---------------------------------------------------------------------------------------------------
struct NodoCelestial {
    string nombreAngel;
    int version, generacion;
    Humano *humanoSalvado;
    NodoCelestial *angelIzquierdo, *angelCentral, *angelDerecho;

    NodoCelestial(string _nombre, int _generacion){
        nombreAngel=_nombre;
        generacion=_generacion;
        angelIzquierdo=angelCentral=angelDerecho=NULL;
        version=0;
        humanoSalvado=NULL;
    }

    void imprimirCelestialmente();
};

// ARBOL ANGELICAL ---------------------------------------------------------------------------------------------
struct ArbolAngelical{
    NodoCelestial *raiz;
    int numeroVersion;

    ArbolAngelical(){
        raiz=new NodoCelestial("DIOS",0);
        numeroVersion=0;
    }

    void generarPrimerNivel();
    void generarNuevoNivel(NodoCelestial *nodo);
    void generarVersiones(NodoCelestial *nodo,string nombre);
    void invocarAngeles();
    int contarHojas(NodoCelestial* nodo);
    void imprimirPreOrden(NodoCelestial *nodo);
    //para salvar llamar a sacar humano mas pecador
    NodoCelestial * salvarHumano(NodoCelestial *nodo, Humano * humanoASalvar);
    string convertirAngelAString(NodoCelestial *angel);
    int contadorNodos(NodoCelestial * nodo);
    string organizarPreOrden(NodoCelestial *nodo, string texto);
};

//-----------------------------------------------------------------------------------------------------------ESTRUCTURA DE DATOS LOQUISIMA
//revisar como se llaman las cosas en EstructuraAVL Main
#define pow2(n) (1 << (n))
struct avl {
   Humano * humano;
   struct avl *l;
   struct avl *r;
};

struct ArbolAVL {
    avl * r;

    int llamarHeight();
    int height(avl *);
    int difference(avl *);
    avl *rr_rotat(avl *);
    avl *ll_rotat(avl *);
    avl *lr_rotat(avl*);
    avl *rl_rotat(avl *);
    avl * balance(avl *);
    avl * insert(avl*, Humano *);
    void show(avl*, int);
    void inorder(avl *);
    string sInorden(avl*);
    void preorder(avl *);
    void postorder(avl*);
    int contarNodos(avl*); //añadido!!
    ArbolAVL() {
        r = NULL;
    }
};



int ArbolAVL::height(avl *t) {
    if (t==NULL){
        t=r;
    }
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}

int ArbolAVL::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}

avl *ArbolAVL::rr_rotat(avl *parent) {

   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}

avl *ArbolAVL::ll_rotat(avl *parent) {

   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}

avl *ArbolAVL::lr_rotat(avl *parent) {

   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}

avl *ArbolAVL::rl_rotat(avl *parent) {

   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}

avl *ArbolAVL::balance(avl *t) {

   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}

avl *ArbolAVL::insert( avl*t, Humano * v) {

   if (t == NULL) {
      t = new avl;
      t->humano = v;
      t->l = NULL;
      t->r = NULL;
      return t;
   } else if (v->ID < t->humano->ID) {
      t->l = insert( t->l,v);
      r = balance(r);
   } else if (v->ID >= t->humano->ID) {
      t->r = insert( t->r,v);
      r = balance(r);
   } return t;
}

void ArbolAVL::show(avl *p, int l) {//de momento no deberian funcionar por como imprimen, se necesita cambiar

   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->humano;
         show(p->l, l + 1);
   }
}

void ArbolAVL::inorder(avl *t) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
   
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->humano << " ";
      inorder(t->r);
}

string ArbolAVL::sInorden(avl*t){

    string result = "";
    if (t != NULL) {
        result += sInorden(t->l);
        result += t->humano->convertirAStringCelestial() + 
        "------------------------------------------------------\n";
        result += sInorden(t->r);
    }
    return result;
}

void ArbolAVL::preorder(avl *t) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
   
   if (t == NULL)
      return;
      cout << t->humano << " ";
      preorder(t->l);
      preorder(t->r);
}

void ArbolAVL::postorder(avl *t) {//de momento no deberian funcionar por como imprimen, se necesita cambiar

   
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->humano << " ";
}

int ArbolAVL::contarNodos(avl* t){

    if (t == NULL)
        return 0;
    else
        return 1+contarNodos(t->l)+contarNodos(t->r);
} 


//CIELO -------------------------------------------------------------------------------------------------------------------------------------

struct Cielo{
    ArbolAngelical * arbolAngelical;
    Infierno * infierno;
    ArbolAVL * tablaSacra[1000];//no se si esto funcionara así sin el new
    BitacoraCondenacion * bitacora;

    Cielo(Infierno* _infierno){
        infierno=_infierno;
        arbolAngelical->generarPrimerNivel();
    }
    void insertarEnTablaHash(Humano*);
    int calcularPosicionEnTabla(int ID);
    void generarBitacoraSalvacion(Humano * humano, string angel,  NodoCelestial *angelEnviado);
    string crearArchivoBitacora();
    //para sacar del infierno ljdsflksdjl ---->>>>>    infierno->sacarHumanoMasPecador();  <<<<-------jdalsdjsalkdjasd (retorna un *humano)
    void tenerPiedad();
    string salvacionGeneral();
    int contarCantidadSalvados();

    void generarConsultaCelestial();


};





