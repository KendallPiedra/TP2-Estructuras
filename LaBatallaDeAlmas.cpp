#include "MetodosHibridos.cpp"

int main(int argc, char const *argv[])
{
    srand(time(0));
    // string cantidadInicial;
    // cout<<"-------------- BIENVENIDO ----------------"<<endl;
    // cout<<"Ingrese la cantidad de humanos a generar: "<<endl;
    // getline(cin, cantidadInicial);
    // -------------------------------------------------------------------------------------------------------------------------
    ArbolDeLaVida * arbolDeLaVida= new ArbolDeLaVida();
    arbolDeLaVida->crearGeneracionHumanos(1000);
    arbolDeLaVida->imprimir();
    arbolDeLaVida->arrayDeLaVida[3]->publicarEnRedSocial(
        arbolDeLaVida->arrayDeLaVida[3]->redesSociales[6]->nombreRedSocial,
        extraerPecadoConRedSocial(arbolDeLaVida->arrayDeLaVida[3]->redesSociales[6]->nombreRedSocial));
    // cout<<"----------------------*************************************************************---------------------------------"<<endl;
    
    menuPublicarPorReligion(arbolDeLaVida);

    cout<<"lista generada..."<<endl;
    std::cin.get(); // Espera que el usuario presione Enter

    Infierno * infierno = new Infierno(arbolDeLaVida);//
    cout<<"cosa2"<<endl;
    infierno-> realizarCondenacionGeneral();
    cout<<"cosa3"<<endl;
    std::cin.get(); // Espera que el usuario presione Enter

    infierno->consultaDeLosMiembrosDelInfierno();
    arbolDeLaVida->imprimir();

    // // cout<<"----------------------*************************************************************---------------------------------"<<endl;
    // arbolDeLaVida->arrayDeLaVida[663]->amigos->imprimirConPecados();
    std::cout << "Presiona Enter para salir...";
    std::cin.get(); // Espera que el usuario presione Enter

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
    // string log="apellidos.txt";
    // string email="krisncl1701@gmail.com";
    // string ruta=""; 
    // ArbolAngelical *arbolAngelical=new ArbolAngelical();
    // arbolAngelical->generarPrimerNivel();
    // arbolAngelical->invocarAngeles();
    // arbolAngelical->invocarAngeles();
    // arbolAngelical->invocarAngeles();
    // arbolAngelical->imprimirInOrden(arbolAngelical->raiz);
    


    return 0;
}
