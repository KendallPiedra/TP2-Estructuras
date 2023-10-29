#include "Estructuras.h"

// NODO ARBOL ----------------------------------------------------------------------------------------

void NodoArbol::imprimir(){
    cout<<dato<<endl;
}

// ARBOL BINARIO -------------------------------------------------------------------------------------
void ArbolDeLaVida::insertar(int dato){
     raiz = insertar(dato, raiz);
}
//  INSERTA RECURSIVAMENTE
NodoArbol* ArbolDeLaVida::insertar(int valor, NodoArbol* nodo){
    if (nodo == NULL){
        return new NodoArbol(valor);
    }      
      // si el valor es mayor, 
      //llama recursivamente a insertar en el hijo
      // derecho
    else if (nodo->dato < valor){
        nodo->hijoderecho = insertar(valor, nodo->hijoderecho);
    }
      // en caso contrario, va al lado izquierdo
    else if (nodo->dato >= valor){
        nodo->hijoizquierdo = insertar(valor, nodo->hijoizquierdo);
    }
    return nodo;
}

void ArbolDeLaVida::inOrdenClientes(NodoArbol* nodo){
    if (nodo != NULL){
        inOrdenClientes(nodo->hijoizquierdo);
        nodo->imprimir();
        inOrdenClientes(nodo->hijoderecho);
    }
}

void ArbolDeLaVida::inOrden(NodoArbol* nodo){
    if (nodo != NULL){
        inOrden(nodo->hijoizquierdo);
        cout << nodo->dato << "  ";
        inOrden(nodo->hijoderecho);
    }
}

void ArbolDeLaVida::preOrden(NodoArbol* nodo){
    if (nodo != NULL){
        cout << nodo->dato << "  ";
        preOrden(nodo->hijoizquierdo);
        preOrden(nodo->hijoderecho);
    }
}

void ArbolDeLaVida::posOrden(NodoArbol* nodo){
    if (nodo != NULL){
        posOrden(nodo->hijoizquierdo);
        posOrden(nodo->hijoderecho);
        cout << nodo->dato << "  ";
    }
}

int ArbolDeLaVida::contadorNodos(NodoArbol* nodo){
    if (nodo == NULL)
        return 0;
    else
        return 1+ contadorNodos(nodo->hijoderecho)+contadorNodos(nodo->hijoizquierdo);
}        
// BUSCA UN VALOR EN EL ARBOL ORDENADO
NodoArbol* ArbolDeLaVida::buscar (int valor, NodoArbol* nodo){
    // cuando el nodo es nulo, quiere decir que all� debe
    // ubicar el valor, en un nuevo nodo
    if (nodo == NULL){
        return NULL;
    }else if (nodo->dato == valor){
        return nodo;
    }else if (nodo->dato < valor){
        // si el valor es mayor, llama recursivamente a insertar en el hijo
        // derecho
        return buscar(valor, nodo->hijoderecho);
    }else{ //(nodo.dato >= valor)
     // en caso contrario, va al lado izquierdo
        return buscar(valor, nodo->hijoizquierdo);
    }
 }
// cantidad de elementos de un arbol binario
int ArbolDeLaVida::obtenerNumeroElementos(NodoArbol* nodo){
    int num_elems = 0;
    if(nodo != NULL){
        num_elems += obtenerNumeroElementos(nodo->hijoizquierdo);
        num_elems++; // contabilizar el nodo visitado
        num_elems += obtenerNumeroElementos(nodo->hijoderecho);
    }
    return num_elems;
}
// obtiene la altura
//Altura. La altura de un �rbol se define como el
//nivel del nodo de mayor nivel. Como cada nodo de un �rbol
//puede considerarse a su vez como la ra�z de un �rbol, tambi�n
//podemos hablar de altura de ramas; el m�ximo n�mero de nodos
//que hay que recorrer para llegar de la ra�z a una de las hojas.
int Arbol::obtenerAltura(NodoArbol* nodo) {
    // resultado
    int altura    = 0;
    // referencias hi e hd
    NodoArbol* ref_h_izq;
    NodoArbol* ref_h_der;
    // resultado de alturas de hi e hd
    int altura_r_izq = 0;
    int altura_r_der = 0;
    //
    if(nodo != NULL){
        // incia en 1 para contar la raiz
        altura = 1;
        // inicialiaza las referencias
        ref_h_izq = nodo->hijoizquierdo;
        ref_h_der = nodo->hijoderecho;
        // si ninguno de los hijos es nulo
        if( (ref_h_izq != NULL) && (ref_h_der != NULL) ) {
            // obtiene las alturas de cada arbol izq y der
            altura_r_izq = obtenerAltura(ref_h_izq);
            altura_r_der = obtenerAltura(ref_h_der);

            // suma la altura mayor, para determinar el mayor nivel
            if(altura_r_izq >= altura_r_der){
                altura += altura_r_izq;
            }else{
                altura += altura_r_der;
            }// hizq no es nulo, suma altura de hijo izquierdo
        }else if( (ref_h_izq != NULL) && (ref_h_der == NULL) ){
            altura += obtenerAltura(ref_h_izq);
        }else if( (ref_h_izq == NULL) && (ref_h_der != NULL) ){// hder no es nulo, suma altura de hijo derecho
            altura += obtenerAltura(ref_h_der);
        }else if( (ref_h_izq == NULL) && (ref_h_der == NULL) ) {// cuando ambos son nulos, resta el uno con el que empez�
            altura -= 1;
        }
    }
    // retorna el resultado
    return altura;
}

int maximo (int a, int b){
    if (a>b)
       return a;
    else return b;    
}

int Arbol::altura (NodoArbol* nodo){
    if (nodo == NULL)
        return -1;
    else 
        return 1 + maximo(altura(nodo->hijoizquierdo),altura(nodo->hijoderecho));
}

int Arbol::cantNodos2 (NodoArbol* nodo){
    if (nodo == NULL)
        return 0;
    else 
        return 1 + cantNodos2(nodo->hijoizquierdo)+cantNodos2(nodo->hijoderecho);
}

int Arbol::cantHojas(NodoArbol* raiz){
    if (raiz == NULL)
       return 0;
    else if (raiz->hijoderecho == NULL && raiz->hijoizquierdo==NULL)
        return 1;
    else
        return cantHojas(raiz->hijoderecho)+cantHojas(raiz->hijoizquierdo);
}
// borrar
NodoArbol* Arbol::mayor (NodoArbol* arbol){
    if (arbol == NULL)
        return NULL;
    else if (arbol->hijoderecho == NULL)
        return arbol;
    else
        return mayor (arbol->hijoderecho);
}

NodoArbol* Arbol::borrarElemento(int ele){
    raiz = borrarElemento(ele, raiz);
    return raiz;
}

NodoArbol* Arbol::borrarElemento(int ele, NodoArbol* arbol){
    if (arbol == NULL){
        return NULL;
    }
    else if (ele < arbol->dato)
        arbol->hijoizquierdo = borrarElemento(ele, arbol->hijoizquierdo);
    else if (ele > arbol->dato)
        arbol->hijoderecho = borrarElemento(ele, arbol->hijoderecho);
    else if (arbol->hijoizquierdo == NULL && arbol->hijoderecho == NULL)
        arbol = NULL;
    else if (arbol->hijoizquierdo == NULL)
        arbol = arbol->hijoderecho;
    else if (arbol->hijoderecho == NULL)
        arbol = arbol->hijoizquierdo;
    else{
        NodoArbol* max = mayor(arbol->hijoizquierdo); // mayor de los menores
        arbol->hijoizquierdo = borrarElemento(max->dato, arbol->hijoizquierdo);
        arbol->dato = max->dato;
    }
    return arbol;   
}

//LISTA DOBLE -----------------------------------------------------------------------------------------
void ListaDoble::insertarInicio(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion){
    if (primerArticulo==0)
	    primerArticulo=ultimoArticulo=new NodoArticulo(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
    else{
	    primerArticulo->anterior= new NodoArticulo(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
	    primerArticulo->anterior->siguiente=primerArticulo;
	    primerArticulo=primerArticulo->anterior;
    }
}

void ListaDoble::insertarFinal(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion){
    if (primerArticulo==0)
	    primerArticulo=ultimoArticulo=new NodoArticulo(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
    else{
	    ultimoArticulo->siguiente= new NodoArticulo(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
	    ultimoArticulo->siguiente->anterior=ultimoArticulo;
	    ultimoArticulo=ultimoArticulo->siguiente; 
    }
}

NodoArticulo * ListaDoble::borrarAlFinal(){
	NodoArticulo * borrado=ultimoArticulo;
	if (primerArticulo!=NULL){
		if (primerArticulo==ultimoArticulo){
			primerArticulo=ultimoArticulo=NULL;
    	}else{
        	ultimoArticulo=ultimoArticulo->anterior;
			borrado->anterior=NULL;
			ultimoArticulo->siguiente=NULL;
    	}
	}
    return borrado;
}

int ListaDoble::largo(){
    // lock_guard<mutex> lock(mtx);
	NodoArticulo * tmp = primerArticulo;
    int contador=0;
    while(tmp!=NULL){
	    contador++;
	    tmp=tmp->siguiente;
    }
	return contador;
}

string ListaDoble::encontrarUbicacionArticulo(string _codigo){
	NodoArticulo * tmp = primerArticulo;
	while(tmp!=NULL){
		if(tmp->codigo==_codigo){
			return tmp->ubicacion;
		}
		tmp=tmp->siguiente;
    }
	return NULL;
}

void ListaDoble::imprimir(){
	NodoArticulo * tmp = primerArticulo;
	while(tmp!=NULL){
		tmp->imprimir();
		tmp=tmp->siguiente;
    }
}

bool ListaDoble::encontrarArticulo(string _codigo){
	NodoArticulo * tmp = primerArticulo;
	while(tmp!=NULL){
		if(tmp->codigo==_codigo){
			return true;
		}
		tmp=tmp->siguiente;
    }
	return false;
}

