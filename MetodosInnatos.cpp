#include "Estructuras.h"
#include "Funciones.cpp"

//HUMANO -------------------------------------------------------------------------------------------------
void Humano::inicializarPecados(){
    //0:Lujuria  
    //1:Gula
    //2:Avaricia
    //3:Pereza
    //4:Ira
    //5:Envidia
    //6:Soverbia 
    string pecadosCapitales[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    Pecado* pecado;
    for (int i=0; i < 7; i++){
        pecado=&pecados[i];
        pecado->nombrePecado=pecadosCapitales[i];
    }
}

void Humano::agregarPecado(string pecado){ //sujeto a cambios
    Pecado* tmp;
    for (int i=0; i < 7; i++){
        tmp=&pecados[i];
        if (tmp->nombrePecado==pecado){
            tmp->cantidad++;
        }
    }
}

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


void ArbolDeLaVida::inOrden(NodoArbol* nodo){
    if (nodo != NULL){
        inOrden(nodo->hijoizquierdo);
        cout << nodo->dato << "  ";
        inOrden(nodo->hijoderecho);
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

int ArbolDeLaVida::altura (NodoArbol* nodo){
    if (nodo == NULL)
        return -1;
    else 
        return 1 + maximo(altura(nodo->hijoizquierdo),altura(nodo->hijoderecho));
}


int ArbolDeLaVida::cantHojas(NodoArbol* raiz){
    if (raiz == NULL)
       return 0;
    else if (raiz->hijoderecho == NULL && raiz->hijoizquierdo==NULL)
        return 1;
    else
        return cantHojas(raiz->hijoderecho)+cantHojas(raiz->hijoizquierdo);
}
// borrar
NodoArbol* ArbolDeLaVida::mayor (NodoArbol* arbol){
    if (arbol == NULL)
        return NULL;
    else if (arbol->hijoderecho == NULL)
        return arbol;
    else
        return mayor (arbol->hijoderecho);
}

//BORRAAAAR
// NodoArbol* Arbol::borrarElemento(int ele){
//     raiz = borrarElemento(ele, raiz);
//     return raiz;
// }

// NodoArbol* Arbol::borrarElemento(int ele, NodoArbol* arbol){
//     if (arbol == NULL){
//         return NULL;
//     }
//     else if (ele < arbol->dato)
//         arbol->hijoizquierdo = borrarElemento(ele, arbol->hijoizquierdo);
//     else if (ele > arbol->dato)
//         arbol->hijoderecho = borrarElemento(ele, arbol->hijoderecho);
//     else if (arbol->hijoizquierdo == NULL && arbol->hijoderecho == NULL)
//         arbol = NULL;
//     else if (arbol->hijoizquierdo == NULL)
//         arbol = arbol->hijoderecho;
//     else if (arbol->hijoderecho == NULL)
//         arbol = arbol->hijoizquierdo;
//     else{
//         NodoArbol* max = mayor(arbol->hijoizquierdo); // mayor de los menores
//         arbol->hijoizquierdo = borrarElemento(max->dato, arbol->hijoizquierdo);
//         arbol->dato = max->dato;
//     }
//     return arbol;   
// }
//</BORRAAAAA>

//NODO PECADO -------------------------------------------------------------------------------------------

//LISTA AMIGUIS -----------------------------------------------------------------------------------------
void NodoAmigo::imprimir(){
    cout<<"Holi"<<endl;
}

void ListaBesties::insertarInicio(Humano *amigo){
    if (primerNodo==NULL)
	    primerNodo=ultimoNodo=new NodoAmigo(amigo);
    else{
	    primerNodo->anterior= new NodoAmigo(amigo);
	    primerNodo->anterior->siguiente=primerNodo;
	    primerNodo=primerNodo->anterior;
    }
}

void ListaBesties::insertarFinal(Humano *amigo){
    if (primerNodo==0)
	    primerNodo=ultimoNodo=new NodoAmigo(amigo);
    else{
	    ultimoNodo->siguiente= new NodoAmigo(amigo);
	    ultimoNodo->siguiente->anterior=ultimoNodo;
	    ultimoNodo=ultimoNodo->siguiente; 
    }
}

NodoAmigo * ListaBesties::borrarAlFinal(){
	NodoAmigo * borrado=ultimoNodo;
	if (primerNodo!=NULL){
		if (primerNodo==ultimoNodo){
			primerNodo=ultimoNodo=NULL;
    	}else{
        	ultimoNodo=ultimoNodo->anterior;
			borrado->anterior=NULL;
			ultimoNodo->siguiente=NULL;
    	}
	}
    return borrado;
}

int ListaBesties::largo(){
	NodoAmigo * tmp = primerNodo;
    int contador=0;
    while(tmp!=NULL){
	    contador++;
	    tmp=tmp->siguiente;
    }
	return contador;
}

bool ListaBesties::tieneAmigo(int IDAmigo){
    NodoAmigo * tmp = primerNodo;
    while(tmp!=NULL){
	    if(IDAmigo==tmp->amigo->ID){
            return true;
        }
	    tmp=tmp->siguiente;
    }
	return false;
}

