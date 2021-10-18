// Ejercicio 10
#include<iostream>
#include <map>
using namespace std;

void CopiarB(int A[], int B[], int tamA, int tamB) {
    // Funcion que copia los elementos de B en A manteniendo el orden.
    int i = tamA - 1;
    int j = tamB - 1;
    int k = tamA + tamB - 1;
    while (j >= 0) {
        if (i >= 0 && A[i] > B[j]) {
            A[k] = A[i];
            i--;
        } 
        else {
            A[k] = B[j];
            j--;
        }
        k--;
    }
}
 
void imprimir(int *A, int tam) {
    for (int i = 0; i < tam; i++)
        cout << A[i] << " ";
}
 
int main() {
    // Caso prueba 1:
    // Entrada: 1 3 5 7 0 0 0 0 - 2 4 6 8
    // Salida: 1 2 3 4 5 6 7 8
    int A[] = {1,3,5,7,0,0,0,0};
    int B[] = {2,4,6,8};
    CopiarB(A, B, 4,4);
    imprimir(A, 8);
    return 0;
}