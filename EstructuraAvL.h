#define pow2(n) (1 << (n))
struct avl {
   Humano * humano;
   struct avl *l;
   struct avl *r;
};

struct avl_tree {
    avl * r;
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
    avl_tree() {
        r = NULL;
    }
};

int avl_tree::height(avl *t=r) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}

int avl_tree::difference(avl *t=r) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}

avl *avl_tree::rr_rotat(avl *parent=r) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}

avl *avl_tree::ll_rotat(avl *parent=r) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}

avl *avl_tree::lr_rotat(avl *parent=r) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}

avl *avl_tree::rl_rotat(avl *parent=r) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}

avl *avl_tree::balance(avl *t=r) {
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

avl *avl_tree::insert( Humano * v, avl *t=r,) {
   if (t == NULL) {
      t = new avl;
      t->humano = v;
      t->l = NULL;
      t->r = NULL;
      return t;
   } else if (v->ID < t->humano->ID) {
      t->l = insert(v, t->l);
      r = balance(r);
   } else if (v->ID >= t->humano->ID) {
      t->r = insert( v, t->r);
      r = balance(r);
   } return t;
}

void avl_tree::show(avl *p=r, int l) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
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

void avl_tree::inorder(avl *t=r) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->humano << " ";
      inorder(t->r);
}

string avl_tree::sInorden(avl*t=r){
    string result = "";
    if (t != NULL) {
        result += sInorden(t->l);
        result += t->humano->convertirAStringCelestial() + 
        "------------------------------------------------------\n";
        result += sInorden(t->r);
    }
    return result;
}

void avl_tree::preorder(avl *t=r) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
   if (t == NULL)
      return;
      cout << t->humano << " ";
      preorder(t->l);
      preorder(t->r);
}

void avl_tree::postorder(avl *t=r) {//de momento no deberian funcionar por como imprimen, se necesita cambiar
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->humano << " ";
}

int avl_tree::contarNodos(avl* t=r){
    if (t == NULL)
        return 0;
    else
        return 1+contarNodos(t->l)+contarNodos(t->r);
} 
