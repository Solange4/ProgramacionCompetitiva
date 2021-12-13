#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool comparar(int a, int b){
    return (a < b);
}
void SquareOrder(vector<int> &array){
    for(int i=0; i<array.size();i++)
        array[i] = pow(array[i],2);
    sort(array.begin(), array.end(),comparar);
      
}

int main(){
    vector<int> array = {-4,-3,1,2,3}; 
    SquareOrder(array);
    for (int i = 0; i < array.size(); i++)
        cout<<array[i]<<" ";
    cout<<endl;
    

    return 0;
}