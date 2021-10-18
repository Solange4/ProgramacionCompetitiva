// Ejercicio 4
#include <iostream>
using namespace std;

class Nodo{
    public:
        Nodo *siguiente;
        int valor;
		Nodo(){siguiente=NULL;}
        Nodo(int nuevoValor){valor=nuevoValor;siguiente=NULL;}
};
class Lista{
    public:
        Nodo * cima;
        int tamanio;
        Lista(){cima = NULL; tamanio = 0;}
        Lista(int nuevoValor){cima = new Nodo();tamanio = 1;}
        ~Lista(){
			while (cima != NULL){
				Nodo* temp = cima;
				cima = cima->siguiente;
				delete temp;
			}
		}
};
class Pila{
    public:
        Lista pila;
        void push(int nuevoValor){
			Nodo *nuevoNodo=new Nodo(nuevoValor);
			Nodo *temp=pila.cima;
			if(!pila.cima)
				pila.cima=nuevoNodo;
			else{   
				nuevoNodo-> siguiente=pila.cima;        
				pila.cima=nuevoNodo;
				while(temp) {
					temp=temp->siguiente;
				}
			}
			pila.tamanio++;
		}
		Nodo* top(){
			if(!pila.cima)
				cout<<"Pila vacia, no hay elemento cima"<<endl;
			else
				return pila.cima;
		}
        bool empty(){
			if(pila.cima==NULL)
				return true;
			else
				return false;
		}
        void mostrar(){
			Nodo* temp = pila.cima;
			if(!pila.cima)
				return;
			else{
				while( temp != NULL){
					cout<< temp->valor<<" ";
					temp = temp->siguiente;
				}
				cout<<endl;
			}
		}
		Nodo* pop(){
			Nodo* temp = pila.cima;
			if(!pila.cima)
				cout<<"Pila vacia, no se puede eliminar elemento"<<endl;
			else{
				pila.cima = temp->siguiente;
				return temp;
				delete temp;
			}
		}
};

void ordAscendente( Pila original){
    /*  Función que ordene una pila de forma ascendente. Las únicas funciones 
        permitidas son push, pop,empty (consulta) y peek o top
    */
	Pila copia;
	while (!original.empty()){
		int num = original.top()->valor;
		original.pop();
		while (!copia.empty() && copia.top()->valor < num){
			original.push(copia.top()->valor);
			copia.pop();
		}
		copia.push(num);		
	}
	copia.mostrar();		
}

int main(){
	// Caso prueba 1:
    // Entrada: 10 9 8 6 4 1 5 3
    // Salida:  1 3 4 5 6 8 9 10
    Pila pila1;
	pila1.push(3);pila1.push(5);pila1.push(1);pila1.push(4);
	pila1.push(6);pila1.push(8);pila1.push(9);pila1.push(10);
	pila1.mostrar();
	ordAscendente(pila1);
    cout<<endl;
	// Caso prueba 2:
    // Entrada: 33 12 54 1 53 4 12 5
    // Salida:  1 4 5 12 12 33 53 54
    Pila pila2;
	pila2.push(5);pila2.push(12);pila2.push(4);pila2.push(53);
	pila2.push(1);pila2.push(54);pila2.push(12);pila2.push(33);
	pila2.mostrar();
	ordAscendente(pila2);
    cout<<endl;
	// Caso prueba 3:
    // Entrada: 55 24 56 13 34 13 24 5
    // Salida:  5 13 13 24 24 34 55 56
    Pila pila3;
	pila3.push(5);pila3.push(24);pila3.push(13);pila3.push(34);
	pila3.push(13);pila3.push(56);pila3.push(24);pila3.push(55);
	pila3.mostrar();
	ordAscendente(pila3);
}