#include <iostream>
#include <vector>
using namespace std;
 

void SumThreeValues(vector <long long> array,long long tam, long long sum){
    for (long long i = 0; i < tam - 2; i++){
        for (long long j = i + 1; j < tam - 1; j++){
            for (long long k = j + 1; k < tam; k++){
                if (array[i] + array[j] + array[k] == sum){
                    cout << i+1 <<" " << j+1 << " " << k+1;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
 
int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> array ; 
    long long a;
    for(long long i=0; i<n; i++){
        cin >> a;
        array.push_back(a);
    }
    SumThreeValues(array, n, x);
    return 0;
}