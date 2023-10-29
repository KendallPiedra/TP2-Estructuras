struct Humano{

} ;

struct BitacoraCondenacion{

};

struct ListaDoble {
	NodoArticulo * primerArticulo, * ultimoArticulo;
	
    ListaDoble(){
		primerArticulo=ultimoArticulo=NULL;
    }

    void insertarInicio(int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
    void insertarFinal (int _cantidad, string _codigo, string _categoria, string _ubicacion, int _tiempoFabricacion);
	NodoArticulo * borrarAlFinal();
    void leerArchivoArticulos();
    void imprimir();
    bool encontrarArticulo(string _codigo);
    void actualizarArchivoArticulos();
    int revisarListaArticulos();
    int largo();
    bool encontrarArticuloRepetido(string _codigo);
    int cantidadArticuloBodega(string _codigo);
    int sacarTiempoFabricacion(string _codigo);
    void apartarProductos(ListaProductos *listaProductos);
    void annadirProductoAlmacen(int cantProducto, string codigoProducto);

        //Destructor
    ~ListaDoble() {
        NodoArticulo* tmp = primerArticulo;
        while (tmp) {
            NodoArticulo* siguiente = tmp->siguiente;
            delete tmp;
            tmp = siguiente;
        }
    }
    string encontrarUbicacionArticulo(string _codigo);
};