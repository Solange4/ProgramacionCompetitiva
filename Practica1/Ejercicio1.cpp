// Ejercicio 1: Producto máximo de dos números en una sequencia
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxProduct(const vector<int>& numbers){
    /*  Dada una secuencia de n números no negativos y mayores que cero.
        Retornar el mayor número que se pueda obtener multiplicando dos números de la secuencia.
    */
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < numbers.size(); i++){
        if(numbers[i] > num1){
			num2 = num1;
			num1 = numbers[i];
		}
		else if (numbers[i] > num2)
			num2 = numbers[i];
    }
    return num2*num1;
} 
 
int main(){
    // Caso prueba 1:
    // Entrada: 8,1,6,3,4,10,3,9,14,2
    // Salida: 140
    vector<int> numbers1{8,1,6,3,4,10,3,9,14,2};
    cout<<MaxProduct(numbers1)<<endl;
    // Caso prueba 2:
    // Entrada: 10,100,80
    // Salida: 8000
    vector<int> numbers2{10,100,80};
    cout<<MaxProduct(numbers2)<<endl;
    // Caso prueba 3:
    // Entrada: 1,2,3
    // Salida: 6
    vector<int> numbers3{1,2,3};
    cout<<MaxProduct(numbers3)<<endl;
    // Caso prueba 4:
    // Entrada: 1000,400,4,6
    // Salida: 400000
    vector<int> numbers4{1000,400,4,6};   
    cout<<MaxProduct(numbers4)<<endl;
    return 0;
}