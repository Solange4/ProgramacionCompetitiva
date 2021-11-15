#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int k = 0, x;
    int cont = 0;
    map<int, int> sol;

    while (k++ < N){
        cin >> x;
        sol[x] = (sol[x] != 0) ? sol[x] + 1 : 1;
        sol[x+1000] = (sol[x+1000] != 0) ? sol[x+1000] -1 : -1;
    }
    vector<int> array(sol.size(), 0);
    for(auto it = sol.begin(); it != sol.end(); it++){
        if(it == sol.begin()) array[cont] = it->second;
        else array[cont] = array[cont-1] + it->second;
        cont++;
    }
    cout << ceil(*max_element(array.begin(), array.end())/(float)K) << endl;
    return 0;
}