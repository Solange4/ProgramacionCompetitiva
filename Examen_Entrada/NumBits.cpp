// Ejercicio 8
#include <iostream>
using namespace std;

void NumBits(int A, int B){
    // Función que determina el número de bits requeridos para transformar 
    // un numero entero A en un numero entero B
    int cont = 0;
    for(int i = A^B; i!=0; i=i>>1){
        cont += i&1;
    }
    cout<< cont << endl;
}

int main(){
    // Caso prueba 1:
    // Entrada: 31, 14
    // Salida: 2
    int A,B;
    // cin>>A>>B;
    A = 31;
    B = 14;
    NumBits(A,B);
}