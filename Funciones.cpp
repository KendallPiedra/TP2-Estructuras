#include <cstdlib>
#include <ctime>

int maximo (int a, int b){
    if (a>b)
       return a;
    else return b;    
}

int generacionNumerosAleatorios() {
    return rand() % 100 + 1;
}