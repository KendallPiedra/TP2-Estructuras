#include "MetodosHibridos.cpp"

int main(int argc, char const *argv[])
{
    srand(time(0));
    // cout<<generacionNumerosAleatorios<<endl;
    // cout<<extraerNombreAleatorio()<<endl;
    // string cantidadInicial;
    // cout<<"-------------- BIENVENIDO ----------------"<<endl;
    // cout<<"Ingrese la cantidad de humanos a generar: "<<endl;
    // getline(cin, cantidadInicial);
    // extraerCantidadNodos();
    
    
    // -------------------------------------------------------------------------------------------------------------------------
    ArbolDeLaVida * arbolDeLaVida= new ArbolDeLaVida();
    arbolDeLaVida->crearGeneracionHumanos(1000);
    // cout<<arbolDeLaVida->cantidadHumanos<<endl;
    arbolDeLaVida->generarAmigosYPecados();
    // cout<<arbolDeLaVida->extraerCantidadNodos()<<endl;
    arbolDeLaVida->ordenarArrayDeLaVida();
    arbolDeLaVida->construirArbol(0,arbolDeLaVida->cantidadHumanos,arbolDeLaVida->extraerCantidadNodos(), 0);
    arbolDeLaVida->imprimir();

    // -------------------------------------------------------------------------------------------------------------------------
    // int opcion=1;
    // do{
    //     // "1: Crear Generación de Humanos"
	//     // "2: Publicar en Redes Sociales"
	//     // "3: La Condenación"
	//     // "4: El Infierno"
	//     // "5: La Salvación"
	//     // "6: El Cielo"
	//     // "7: Consultas"
	//     // "0: SALIR"
    //     opcion=menuPrincipal();
    //     switch (opcion){
    //     case 1:
            
    //         break;
    //     case 2:
            
    //         break;
    //     case 3:
            
    //         break;
    //     case 4:
            
    //         break;
    //     case 5:
            
    //         break;
    //     case 6:
            
    //         break;
    //     case 7:
            
    //         break;
    //     case 0:
    //         break;
    //     default:
            
    //         break;
    //     }
    // } while (opcion!=0);
    return 0;
}
