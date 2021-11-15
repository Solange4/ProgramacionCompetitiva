#include <iostream>
#include <vector>
using namespace std;

void Suma(vector<pair<int,int>> &array, int n, int x){
    int i=0; 
    int j=n-1;
    while (i<j){
        if((array[i].second + array[j].second) == x) 
            break;
        else if((array[i].second + array[j].second) > x) 
            j--;
        else if ((array[i].second + array[j].second) < x) 
            i++;
    }
    if(i<j)
        cout <<array[i].first<<" "<<array[j].first<<endl;
}

int main(){
    // Caso prueba 1:
    // Entrada: [1,2,7,9,11,15] - x = 11
    // Salida: [1,3]
    int n = 6, x = 11;
    vector<pair<int,int>> array = {{0,1},{1,2},{2,7},{3,9},{4,11},{5,15}}; 
    Suma(array, n, x);
    // Caso prueba 2:
    // Entrada: [-1,1,2,3,5] - x = 5
    // Salida: [2,3]
    int n1 = 5, x1 = 5;
    vector<pair<int,int>> array1 = {{0,-1},{1,1},{2,2},{3,3},{4,5}}; 
    Suma(array1, n1, x1);

    return 0;
}