#include <iostream>
#include <vector>
using namespace std;
 
int max(int a, int b) { return (a > b) ? a : b; }
 
int knapSack(int W, int weight[], int value[], int n){
    if (n == 0 || W == 0)
        return 0;
    if (weight[n - 1] > W)
        return knapSack(W, weight, value, n - 1);
    else
        return max(
            value[n - 1]
                + knapSack(W - weight[n - 1],
                           weight, value, n - 1),
            knapSack(W, weight, value, n - 1));
}
 
int main(){
    int n = 5;
    int weight[] = {0,1,2,4,2,5};
    int value[] = {0,5,3,5,3,2};
    int W = 10;
    cout << knapSack(W, weight, value, n);
    return 0;
}
