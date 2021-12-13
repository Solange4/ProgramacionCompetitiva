#include <iostream>
#include <vector>
using namespace std;
 
void BusquedaBinaria(vector< vector<int> > &Matriz, int i, int j,int k, int x){
    while (j <= k){
        int h = (j + k) / 2;
        if (Matriz[i][h] == x){
            cout << "Verdadero"<<endl;
            return;
        }
        else if (Matriz[i][h] > x)
            k = h - 1;
        else
            j = h + 1;
    }
    cout << "Falso"<<endl;
}
void Buscar(vector< vector<int> > &Matriz, int f,int c, int x){
    if (f == 1){
        BusquedaBinaria(Matriz, 0, 0, c-1, x);
        return;
    }
    int i = 0;
    int j = f-1;
    int k = c/2;
    while ((i+1) < j){
        int i_mid = (i + j) / 2;
        if (Matriz[i_mid][k] == x){
            cout << "Verdadero";
            return;
        }
        else if (Matriz[i_mid][k] > x)
            j = i_mid;
        else
            i = i_mid;
    }
    if (Matriz[i][k] == x)
        cout << "Verdadero"<<endl;
    else if (Matriz[i+1][k] == x)
        cout << "Verdadero"<<endl;
    else if (x <= Matriz[i][k-1])
        BusquedaBinaria(Matriz, i, 0, k-1, x);
    else if (x >= Matriz[i][k+1]  &&
             x <= Matriz[i][c-1])
       BusquedaBinaria(Matriz, i, k+1, c-1, x);
    else if (x <= Matriz[i+1][k-1])
        BusquedaBinaria(Matriz, i+1, 0, k-1, x);
    else
        BusquedaBinaria(Matriz, i+1, k+1, c-1, x);
}

int main(){
    // Caso prueba 1:
    // Entrada: {{1,3,5},{7,9,11},{13,15,17}} - x = 7
    // Salida: Verdadero
    int filas = 3, columnas = 3;
    vector< vector<int> > Matriz = {{1,3,5},{7,9,11},{13,15,17}};
    int x1 = 7, x2 = 12;
    Buscar(Matriz, filas, columnas, x1);
    // Caso prueba 2:
    // Entrada: {{1,3,5},{7,9,11},{13,15,17}} - x = 12
    // Salida: Falso
    Buscar(Matriz, filas, columnas, x2);
    return 0;
}