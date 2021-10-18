// Ejercicio 3
#include <iostream>
using namespace std;
#include<time.h>

class Nodo{
    public:
        Nodo *siguiente;
        int elemento;
};
class ListaSEnlazada{
    public:
        Nodo* head;
        int tamanio;
        ListaSEnlazada(){ head = NULL; tamanio = 0; }
        ListaSEnlazada(int nuevoElemento){ head = new Nodo(); tamanio = 1; }
        ~ListaSEnlazada(){
            while (head != NULL){
                Nodo* temp = head;
                head = head->siguiente;
                delete temp;
            }
        }
        void insertar(int val);
        void print();
};
void ListaSEnlazada::insertar(int valor){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->elemento = valor;
    if(head == NULL){ 
       head = nuevoNodo;
    }
    else{
        Nodo* temp = head;
        while(temp->siguiente!=NULL){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo; 
    }
    tamanio++;
}
void ListaSEnlazada :: print(){
    Nodo* temp = head;
    if(!head)
        cout<<"Sin elementos";
    while( temp != NULL){
        cout<< temp->elemento <<" ";
        temp = temp->siguiente;
    }
    cout<<endl;
}

void Suma(ListaSEnlazada A, ListaSEnlazada B){
    /*  Función que sume dos números. Tanto los números como el resultado están representados 
        con una lista enlazada. Cada digito es almacenado en un nodo. Los dígitos son almacenados 
        en orden reverso.
    */
    ListaSEnlazada S;
    Nodo * tempA = A.head;
    Nodo * tempB = B.head;
    int lleva = 0;
    while (tempA != NULL && tempB != NULL){        
        int rpta = tempA->elemento + tempB->elemento + lleva;
        if (rpta >= 10){
            S.insertar(rpta-10);
            lleva = 1;
        }
        else{
            S.insertar(rpta);
            lleva = 0;
        }                   
        tempA = tempA -> siguiente;
        tempB = tempB -> siguiente;    
    }
    while(tempA!=NULL){
        S.insertar(tempA->elemento + lleva);
        tempA = tempA ->siguiente;
        lleva=0;
    }
    while(tempB!=NULL){
        S.insertar(tempB->elemento + lleva);
        tempB = tempB ->siguiente;
        lleva=0;
    }
    if(lleva>0){
        S.insertar(1);
    }
    S.print();   
}

int main(){
    // Caso prueba 1:
    // Entrada: [3->1->5] + [5->9->2]
    // Salida: [8->0->8]
    ListaSEnlazada L1, L2;
    L1.insertar(3);L1.insertar(1);L1.insertar(5);
    L2.insertar(5);L2.insertar(9);L2.insertar(2);
    L1.print();
    L2.print();
    Suma(L1,L2);
    cout<<endl;
    // Caso prueba 2:
    // Entrada: [5->8->4->9] + [5->9->1->1]
    // Salida: [0->8->6->0->1]
    ListaSEnlazada L3, L4;
    L3.insertar(5);L3.insertar(8);L3.insertar(4);L3.insertar(9);
    L4.insertar(5);L4.insertar(9);L4.insertar(1);L4.insertar(1);
    L3.print();
    L4.print();
    Suma(L3,L4);
    cout<<endl;
    // Caso prueba 1:
    // Entrada: [4->7->4->1->6] + [7->9]
    // Salida: [1->7->5->1->6]
    ListaSEnlazada L5, L6;
    L5.insertar(4);L5.insertar(7);L5.insertar(4);L5.insertar(1);L5.insertar(6);
    L6.insertar(7);L6.insertar(9);
    L5.print();
    L6.print();
    Suma(L5,L6);
}