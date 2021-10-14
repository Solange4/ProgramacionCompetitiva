// Ejercicio 2
#include <iostream>
using namespace std;
#include<time.h>

class Nodo{
    public:
        Nodo *siguiente;
        int elemento;
};
class ListaSEnlazada{
    private:
        int tamanio;
        Nodo* head;
    public:
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
        void elimDuplicados();
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
void ListaSEnlazada :: elimDuplicados(){
    //Función para eliminar elementos duplicados de una lista enlazadas no ordenada.
    if(!head)
        return;
    else{
        Nodo* aux1 = head;
        Nodo* aux2;
        Nodo* temp;
        while (aux1 != NULL && aux1->siguiente != NULL){
            aux2 = aux1;
            while (aux2->siguiente != NULL){
                if (aux1->elemento == aux2->siguiente->elemento){
                    temp = aux2->siguiente;
                    aux2->siguiente = aux2->siguiente->siguiente;
                    delete temp;
                    tamanio--;
                }
                else
                    aux2 = aux2->siguiente;
            }   
            aux1 = aux1->siguiente;         
        }
        

    }
}


int main(){
    // Caso prueba 1:
    // Entrada: 5,4,6,2,9,5,4,8,7,0
    // Salida: 5,4,6,2,9,8,7,0
    ListaSEnlazada L1;
    L1.insertar(5);L1.insertar(4);L1.insertar(6);L1.insertar(2);L1.insertar(9);
    L1.insertar(5);L1.insertar(4);L1.insertar(8);L1.insertar(7);L1.insertar(0);
    cout<<"Lista inicial: "; L1.print();
    L1.elimDuplicados();
    cout<<"Lista sin duplicados: "; L1.print(); cout<<endl;
    // Caso prueba 2:
    // Entrada: 12,23,11,24,23,12,11,8,8,10
    // Salida: 12,23,11,24,8,10
    ListaSEnlazada L2;
    L2.insertar(12);L2.insertar(23);L2.insertar(11);L2.insertar(24);L2.insertar(23);
    L2.insertar(12);L2.insertar(11);L2.insertar(8);L2.insertar(8);L2.insertar(10);
    cout<<"Lista inicial: "; L2.print();
    L2.elimDuplicados();
    cout<<"Lista sin duplicados: "; L2.print(); cout<<endl;
    // Caso prueba 3:
    // Entrada: 14,12,34,23,23,14,12,34,4,5
    // Salida: 14,12,34,23,4,5
    ListaSEnlazada L3;
    L3.insertar(14);L3.insertar(12);L3.insertar(34);L3.insertar(23);L3.insertar(23);
    L3.insertar(14);L3.insertar(12);L3.insertar(34);L3.insertar(4);L3.insertar(5);
    cout<<"Lista inicial: "; L3.print();
    L3.elimDuplicados();
    cout<<"Lista sin duplicados: "; L3.print();
}