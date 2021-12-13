#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
 
vector<int> maxSlidingWindow(vector<int>& array, int k) {
    vector<int> rpta;
    for (int i = 0; i <= array.size() - k; i++){
        int max = array[i];
        for (int j = 1; j < k; j++){
            if (array[i + j] > max)
                max = array[i + j];
        }
        rpta.push_back(max);
    }
    return rpta;
}
 
int main(){
    vector<int> array = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> rpta = maxSlidingWindow(array,k);
    cout<<"[ ";
    for(int i=0;i<rpta.size();i++)
        cout<<rpta[i]<<" ";
    cout<<"]";
    return 0;
}