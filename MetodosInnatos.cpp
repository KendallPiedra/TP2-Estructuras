#include "Estructuras.h"
#include "Funciones.cpp"

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





//LISTA DOBLE -----------------------------------------------------------------------------------------
//LISTA HUMANOS -----------------------------------------------------------------------------------------

void ListaDoble::insertarInicio(int numero){
    if (primerHumano==NULL)
	    primerHumano=ultimoHumano=new Nodo(numero);
    else{
	    primerHumano->anterior= new Nodo(numero);
	    primerHumano->anterior->siguiente=primerHumano;
	    primerHumano=primerHumano->anterior;
    }
}

void ListaDoble::insertarFinal(int numero){
    if (primerHumano==0)
	    primerHumano=ultimoHumano=new Nodo( numero);
    else{
	    ultimoHumano->siguiente= new Humano( numero);
	    ultimoHumano->siguiente->anterior=ultimoHumano;
	    ultimoHumano=ultimoHumano->siguiente; 
    }
}

Nodo * ListaDoble::borrarAlFinal(){
	Nodo * borrado=ultimoHumano;
	if (primerHumano!=NULL){
		if (primerHumano==ultimoHumano){
			primerHumano=ultimoHumano=NULL;
    	}else{
        	ultimoHumano=ultimoHumano->anterior;
			borrado->anterior=NULL;
			ultimoHumano->siguiente=NULL;
    	}
	}
    return borrado;
}

int ListaDoble::largo(){
	Nodo * tmp = primerHumano;
    int contador=0;
    while(tmp!=NULL){
	    contador++;
	    tmp=tmp->siguiente;
    }
	return contador;
}


void ListaDoble::imprimir(){
	Nodo * tmp = primerHumano;
	while(tmp!=NULL){
		tmp->imprimir();
		tmp=tmp->siguiente;
    }
}


//LISTA PECADITOS -----------------------------------------------------------------------------------------

// void ListaPecados::insertarInicio(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion){
//     if (primerHumano==0)
// 	    primerHumano=ultimoHumano=new Humano(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
//     else{
// 	    primerHumano->anterior= new Humano(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
// 	    primerHumano->anterior->siguiente=primerHumano;
// 	    primerHumano=primerHumano->anterior;
//     }
// }

// void ListaPecados::insertarFinal(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion){
//     if (primerHumano==0)
// 	    primerHumano=ultimoHumano=new Humano(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
//     else{
// 	    ultimoHumano->siguiente= new Humano(_cantidad, _codigo, _categoria, _ubicacion, _tiempoFabricacion);
// 	    ultimoHumano->siguiente->anterior=ultimoHumano;
// 	    ultimoHumano=ultimoHumano->siguiente; 
//     }
// }

// Humano * ListaPecados::borrarAlFinal(){
// 	Humano * borrado=ultimoHumano;
// 	if (primerHumano!=NULL){
// 		if (primerHumano==ultimoHumano){
// 			primerHumano=ultimoHumano=NULL;
//     	}else{
//         	ultimoHumano=ultimoHumano->anterior;
// 			borrado->anterior=NULL;
// 			ultimoHumano->siguiente=NULL;
//     	}
// 	}
//     return borrado;
// }

// int ListaPecados::largo(){
//     // lock_guard<mutex> lock(mtx);
// 	Humano * tmp = primerHumano;
//     int contador=0;
//     while(tmp!=NULL){
// 	    contador++;
// 	    tmp=tmp->siguiente;
//     }
// 	return contador;
// }

// string ListaPecados::encontrarUbicacionHumaultimoHumano(string _codigo){
// 	Humano * tmp = primerHumano;
// 	while(tmp!=NULL){
// 		if(tmp->codigo==_codigo){
// 			return tmp->ubicacion;
// 		}
// 		tmp=tmp->siguiente;
//     }
// 	return NULL;
// }

// void ListaPecados::imprimir(){
// 	Humano * tmp = primerHumano;
// 	while(tmp!=NULL){
// 		tmp->imprimir();
// 		tmp=tmp->siguiente;
//     }
// }

// bool ListaPecados::encontrarHumaultimoHumano(string _codigo){
// 	Humano * tmp = primerHumano;
// 	while(tmp!=NULL){
// 		if(tmp->codigo==_codigo){
// 			return true;
// 		}
// 		tmp=tmp->siguiente;
//     }
// 	return false;
// }