#include "MetodosHibridos.cpp"

struct NodoAvl {
    Humano * humano;
    NodoAvl *hijoIzq;
    NodoAvl *hijoDerecho;

    NodoAvl(Humano *_humano){
        humano=_humano;
        hijoIzq=hijoDerecho=NULL;
    }
};

struct ArbolAVL {
    NodoAvl * r;
    int heights(NodoAvl *);
    int differences(NodoAvl *);
    NodoAvl *rr_rotat(NodoAvl *);
    NodoAvl *ll_rotat(NodoAvl *nodo);
    NodoAvl *lr_rotat(NodoAvl *nodo);
    NodoAvl *rl_rotat(NodoAvl *nodo);
    NodoAvl * balance(NodoAvl *);
    NodoAvl* insert(Humano* humano, NodoAvl* nodo);
    void preorder(NodoAvl *nodo);
    ArbolAVL() {
        r = NULL;
    }
};

int ArbolAVL::heights(NodoAvl * nodo) {
   if (nodo == NULL) {
        return 0;
    } else {
        int alturaIzquierdo = heights(nodo->hijoIzq);
        int alturaDerecho = heights(nodo->hijoDerecho);
        return 1 + maximo(alturaIzquierdo, alturaDerecho);
    }
}

int ArbolAVL::differences(NodoAvl *nodo) {
    int alturaIzquierdo = heights(nodo->hijoIzq);
    int alturaDerecho = heights(nodo->hijoDerecho);
    int b_factor = alturaIzquierdo - alturaDerecho;
    return b_factor;
}

NodoAvl* ArbolAVL::ll_rotat(NodoAvl* parent) {
    NodoAvl* t = parent->hijoIzq;
    parent->hijoIzq = t->hijoDerecho;
    t->hijoDerecho = parent;
    cout << "Left-Left Rotation\n";
    return t;
}

NodoAvl* ArbolAVL::lr_rotat(NodoAvl* parent) {
    parent->hijoIzq = rr_rotat(parent->hijoIzq);
    return ll_rotat(parent);
}

NodoAvl* ArbolAVL::rl_rotat(NodoAvl* parent) {
    parent->hijoDerecho = ll_rotat(parent->hijoDerecho);
    return rr_rotat(parent);
}

NodoAvl* ArbolAVL::rr_rotat(NodoAvl* parent) {
    NodoAvl* t = parent->hijoDerecho;
    parent->hijoDerecho = t->hijoIzq;
    t->hijoIzq = parent;
    cout << "Right-Right Rotation\n";
    return t;
}

NodoAvl* ArbolAVL::balance(NodoAvl* nodo) {
    int bal_factor = differences(nodo);
    if (bal_factor > 1) {
        if (differences(nodo->hijoIzq) > 0)
            nodo = ll_rotat(nodo);
        else
            nodo = lr_rotat(nodo);
    } else if (bal_factor < -1) {
        if (differences(nodo->hijoDerecho) > 0)
            nodo = rl_rotat(nodo);
        else
            nodo = rr_rotat(nodo);
    }
    return nodo;
}

NodoAvl* ArbolAVL::insert(Humano* humano, NodoAvl* nodo) {
    if (nodo == NULL) {
        return new NodoAvl(humano);
    } else if (humano->ID < nodo->humano->ID) {
        nodo->hijoIzq = insert(humano, nodo->hijoIzq);
        nodo = balance(nodo);
    } else if (humano->ID >= nodo->humano->ID) {
        nodo->hijoDerecho = insert(humano, nodo->hijoDerecho);
        nodo = balance(nodo);
    }
    return nodo;
}

void ArbolAVL::preorder(NodoAvl *nodo) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
    if (nodo == NULL)
        return;
    cout << nodo->humano->ID<< endl;
    preorder(nodo->hijoIzq);
    preorder(nodo->hijoDerecho);
}

int main(int argc, char const *argv[]){
    ArbolAVL *arbolito=new ArbolAVL();
    arbolito->r=arbolito->insert(new Humano(10,"Pepe","Holis","Papa", "creencia","prof", "Nac",13),arbolito->r);
    arbolito->r=arbolito->insert(new Humano(20,"Pepe","Holis","Papa", "creencia","prof", "Nac",13),arbolito->r);
    arbolito->r=arbolito->insert(new Humano(30,"Pepe","Holis","Papa", "creencia","prof", "Nac",13),arbolito->r);
    arbolito->preorder(arbolito->r);
    return 0;
}
