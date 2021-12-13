// Ejercicio 2. Encontrar bucles en un flujo de datos
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ExisBucle (const vector<int> numbers){
    /*  Dada una secuencia de elementos en un flujo de datos determinar si existen bucles.
        Retornar la secuencia que corresponde al bucle.
    */
    vector<int> temp;
    for (int i = 0; i < numbers.size(); i++){
        for (int j = numbers.size()-1; j > i; j--){
            if(numbers[i] == numbers[j] && numbers[i+1] == numbers[j+1]){
                temp.push_back(numbers[j]);
                break;
            }
        }            
    }
    return temp;
}
void print(const vector<int> numbers){
    int n=count(numbers.begin(),numbers.end(),numbers[0]);
    for (int i = 0; i < numbers.size()/n; i++)
        cout<<numbers[i]<<" "; 
    cout<<endl;
}

int main (){
    // Caso prueba 1:
    // Entrada: 1,2,3,4,5,2,3,4,5,2,3,4,5,2
    // Salida: 2,3,4,5
    vector<int> numbers1{1,2,3,4,5,2,3,4,5,2,3,4,5,2};
    print(ExisBucle(numbers1));
    // Caso prueba 2:
    // Entrada: 1,2,3,4,5,6,3,7,8,9,10,11,8,9,10,11,8,9,10,11,8
    // Salida: 8,9,10,11
    vector<int> numbers2{1,2,3,4,5,6,3,7,8,9,10,11,8,9,10,11,8,9,10,11,8};
    print(ExisBucle(numbers2));
    // Caso prueba 3:
    // Entrada: 1,2,3,4,5,6,7,8,9,6,5,4,10,11,3,4,5,6,7,8,9,6,5,4,10,11,3
    // Salida: 3,4,5,6,7,8,9,6,5,4,10,11
    vector<int> numbers3{1,2,3,4,5,6,7,8,9,6,5,4,10,11,3,4,5,6,7,8,9,6,5,4,10,11,3};   
    print(ExisBucle(numbers3));
}