// Ejercicio 9
#include <iostream>
using namespace std;
 
int NumFibonacci(int n){
    // Función que genera el numero n de la secuencia Fibonacci
    int aux1 = 0;
    int aux2 = 1;
    int temp;
    if( n == 0)
        return aux1;
    for(int i = 2; i <= n; i++){
       temp = aux1 + aux2;
       aux1 = aux2;
       aux2 = temp;
    }
    return aux2;
}
 
int main(){
    // Caso prueba 1:
    // Entrada: 5
    // Salida: 5
    int n1 = 5;
    cout << NumFibonacci(n1)<<endl;
    // Caso prueba 2:
    // Entrada: 6
    // Salida: 8
    int n2 = 6;
    cout << NumFibonacci(n2)<<endl;
    // Caso prueba 3:
    // Entrada: 10
    // Salida: 55
    int n3 = 10;
    cout << NumFibonacci(n3)<<endl;
    return 0;
}