#include <iostream>
#include <vector>
using namespace std;
 

void Suma(vector <int> array, int sum){
    for (int i = 0; i < array.size() - 2; i++){
        for (int j = i + 1; j < array.size() - 1; j++){
            for (int k = j + 1; k < array.size(); k++){
                if (array[i] + array[j] + array[k] == sum){
                    cout << i <<" " << j << " " << k;
                    return;
                }
            }
        }
    }
}
 
int main(){
    // Caso prueba 1:
    // Entrada: [,1,2,4,5,12] - x = 19
    // Salida: [1,3,4]
    vector <int> array = { 1,2,4,5,12 };
    int x = 19;
    Suma(array, x);
    return 0;
}