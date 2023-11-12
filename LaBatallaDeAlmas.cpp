#include "MetodosHibridos.cpp"

int main(int argc, char const *argv[])
{
    srand(time(0));
    // string cantidadInicial;
    // cout<<"-------------- BIENVENIDO ----------------"<<endl;
    // cout<<"Ingrese la cantidad de humanos a generar: "<<endl;
    // getline(cin, cantidadInicial);
    // ----------------------------------------------asdssdd---------------------------------------------------------------------------
    ArbolDeLaVida * arbolDeLaVida= new ArbolDeLaVida();
    arbolDeLaVida->crearGeneracionHumanos(1000);
    // arbolDeLaVida->imprimir();
    arbolDeLaVida->arrayDeLaVida[3]->publicarEnRedSocial(
        arbolDeLaVida->arrayDeLaVida[3]->redesSociales[6]->nombreRedSocial,
        extraerPecadoConRedSocial(arbolDeLaVida->arrayDeLaVida[3]->redesSociales[6]->nombreRedSocial));
    // // cout<<"----------------------*************************************************************---------------------------------"<<endl;
    
    // // menuPublicarPorReligion(arbolDeLaVida);
    // // menuPublicarPorReligion(arbolDeLaVida);
    // // menuPublicarPorReligion(arbolDeLaVida);
    // cout<<"lista generada..."<<endl;
    // std::cin.get(); // Espera que el usuario presione Enter

    // Infierno * infierno = new Infierno(arbolDeLaVida);//

    // cout<<"cosa2"<<endl;
    // // cosa=infierno-> realizarCondenacionGeneral();
    // // string invocar="C:\\Users\\krisc\\OneDrive\\Escritorio\\Homeworks\\2k23-II-SEMESTRE\\Estructuras-de-Datos\\TP2-Estructuras\\enviarCorreos.exe kpiedra262@gmail.com C:\\Users\\krisc\\OneDrive\\Escritorio\\Homeworks\\2k23-II-SEMESTRE\\Estructuras-de-Datos\\TP2-Estructuras\\"+cosa+" "+cosa+" AHHHHHHHHH";
    // // system(invocar.c_str());
    // // cout<<"enter para realizar consulta..."<<endl;

    // Cielo * cielo= new Cielo(infierno);
    // cout<<"Enter Para Incertar Un Humano..."<<endl;
    // std::cin.get(); // Espera que el usuario presione Enter

    // cielo->insertarEnTablaHash(arbolDeLaVida->arrayDeLaVida[4]);
    

    // // infierno->consultaDeLosMiembrosDelInfierno();
    // // cout<<"se genero la primera consulta"<<endl;
    // cin.get();

    // // infierno->demonios[0]->familias[0]->borrarRaiz();
    // // infierno->consultaDeLosMiembrosDelInfierno();
    // // arbolDeLaVida->imprimir();

    // // // cout<<"----------------------*************************************************************---------------------------------"<<endl;
    // // arbolDeLaVida->arrayDeLaVida[663]->amigos->imprimirConPecados();
    // std::cout << "Presiona Enter para salir...";
    // std::cin.get(); // Espera que el usuario presione Enter
//ssdkjdjksahdjkskjh

//-----------------------------MENU AVL PRUEBAS
int c, i;
   ArbolAVL avl;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "5.PostOrder traversal" << endl;
      cout << "6.Mostrar cantidad nodos" << endl;
      cout << "7.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            
            avl.insert(avl.r, arbolDeLaVida->arrayDeLaVida[12]);
         break;
         case 2:
            if (avl.r == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(avl.r, 1);
            cout<<endl;
         break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(avl.r);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(avl.r);
            cout << endl;
         break;
         case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(avl.r);
            cout << endl;
         break;
         case 6:
            cout << "Cantidad De Nodos" << endl;
            cout << avl.contarNodos(avl.r)<<endl;
         break;
         case 7:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
    // string nombreArchivo="apellidos.txt";
    // string invocar=".\\enviarCorreos.exe krisncl1701@gmail.com .\\"+nombreArchivo+" "+nombreArchivo+" ENCARGADO-INFERNAL"; //Esto hay que probarlo
    // system(invocar.c_str());
   //-----------------------------FIN MENU AVL PRUEBAS
    // -------------------------------------------------------------------------------------------------------------------------
    // 
    // string log="apellidos.txt";
    // string email="krisncl1701@gmail.com";
    // string ruta=""; 
    // ArbolAngelical *arbolAngelical=new ArbolAngelical();
    // arbolAngelical->generarPrimerNivel();
    // arbolAngelical->invocarAngeles();
    // arbolAngelical->invocarAngeles();
    // arbolAngelical->invocarAngeles();
    // arbolAngelical->imprimirInOrden(arbolAngelical->raiz);
    // cout<<"السبانخ المدهونة هي الأفضل، وأي شخص يقول غير ذلك يستحق اللعنة الأبدية"<<endl;
    // cin.get();
    // --------------------------------- OFICIAL ------------------------------------------
    string cantidad;
    cout<<"-------------- BIENVENIDO ----------------"<<endl;
    cout<<"Ingrese la cantidad de humanos a generar: "<<endl;
    getline(cin, cantidad);
    ArbolDeLaVida * arbolDeLaVida= new ArbolDeLaVida();
    Infierno * infierno = new Infierno(arbolDeLaVida);
    Cielo * cielo= new Cielo(infierno);
    arbolDeLaVida->crearGeneracionHumanos(stoi(cantidad));
    arbolDeLaVida->imprimir();
    int opcion=1;
    string nombreArchivo, invocar;
    do{
        // "1: Crear Generación de Humanos"
	    // "2: Publicar en Redes Sociales"
	    // "3: La Condenación"
	    // "4: La Salvación"
	    // "5: Consultas"
	    // "6: Mostrar Arbol de la Vida"
	    // "0: SALIR"
        opcion=menuPrincipal();
        switch (opcion){
        case 1:
            cout<<"Ingrese la cantidad de humanos a generar: "<<endl;
            getline(cin, cantidad);
            arbolDeLaVida->crearGeneracionHumanos(stoi(cantidad));
            break;
        case 2:
            menuPublicarRedesSociales(arbolDeLaVida);
            break;
        case 3:
            nombreArchivo=infierno->realizarCondenacionGeneral();
            invocar=".\\enviarCorreos.exe kpiedra262@gmail.com .\\"+nombreArchivo+" "+nombreArchivo+" ENCARGADO-DEL-INFIERNO"; //Esto hay que probarlo
            system(invocar.c_str());
            break;
        case 4:
            nombreArchivo=cielo->salvacionGeneral();
            invocar=".\\enviarCorreos.exe krisncl1701@gmail.com .\\"+nombreArchivo+" "+nombreArchivo+" ENCARGADO-DEL-CIELO"; //Esto hay que probarlo
            system(invocar.c_str());
            break;
        case 5:
            menuConsultas(arbolDeLaVida,infierno, cielo);
            break;
        case 6:
            arbolDeLaVida->imprimir();
            break;
        case 0:
            break;
        default:
            cout<<"La opción escogida no existe"<<endl;
            break;
        }
    } while (opcion!=0);

    return 0;
}
