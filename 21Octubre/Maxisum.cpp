#include <iostream>
#include <vector>
using namespace std;
 
int Maxisum(vector<int> &array, int k){
   int n = array.size();
   if (n < k)
      return  -1;
   int temp = 0;
   for (int i=0; i<k; i++)
      temp += array[i];
   int suma = temp;
   for (int i=k; i<n; i++){
      suma += array[i] - array[i-k];
      temp = max(temp, suma);
   }
   return temp;
}

int main(){
   vector<int> array = {2,3,4,1,5};
   int k = 3;
   cout << Maxisum(array,k);
   return 0;
}