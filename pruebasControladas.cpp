#include "pruebaKris.cpp";

int main(int argc, char const *argv[]){
    Humano * humano1=new Humano(1234,"Pepe1","Ramirez","Alemania","Islam","Chef", "Hoy", 23);
    humano1->totalPecados=23;
    Humano * humano2=new Humano(5204,"Pepe2","Ramirez","Alemania","Islam","Chef", "Hoy", 23);
    humano2->totalPecados=23;
    Humano * humano3=new Humano(5004,"Pepe3","Ramirez","Alemania","Islam","Chef", "Hoy", 23);
    humano3->totalPecados=23;
    Humano * humano4=new Humano(40234,"Pepe4","Ramirez","Alemania","Islam","Chef", "Hoy", 23);
    humano4->totalPecados=23;
    Humano * humano5=new Humano(45034,"Pepe5","Ramirez","Alemania","Islam","Chef", "Hoy", 23);
    humano5->totalPecados=23;

    ArbolAVL * tablaSacra[1000];
    for (int i=0; i<1000;i++){
        tablaSacra[i]=new ArbolAVL();
    }

    tablaSacra[humano1->ID%1000]->r=tablaSacra[humano1->ID%1000]->insert(tablaSacra[humano1->ID%1000]->r,humano1);
    cout<<"Lo Hice 1"<<endl;
    tablaSacra[humano2->ID%1000]->r=tablaSacra[humano2->ID%1000]->insert(tablaSacra[humano2->ID%1000]->r,humano2);
    cout<<"Lo Hice 2"<<endl;
    tablaSacra[humano3->ID%1000]->r=tablaSacra[humano3->ID%1000]->insert(tablaSacra[humano3->ID%1000]->r,humano3);
    cout<<"Lo Hice 3"<<endl;
    tablaSacra[humano4->ID%1000]->r=tablaSacra[humano4->ID%1000]->insert(tablaSacra[humano4->ID%1000]->r,humano4);
    cout<<"Lo Hice 4"<<endl;
    tablaSacra[humano5->ID%1000]->r=tablaSacra[humano5->ID%1000]->insert(tablaSacra[humano5->ID%1000]->r,humano5);
    cout<<"Lo Hice 5"<<endl;

    return 0;
}
