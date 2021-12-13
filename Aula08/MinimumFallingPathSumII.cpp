#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int MFPS(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 1; i < n; i++) {
        vector<int> izq(m);
        vector<int> der(m);
        izq[0] = arr[i - 1][0];
        for (int j = 1; j < m; j++)
            izq[j] = min(izq[j - 1], arr[i - 1][j]);
        der[m - 1] = arr[i - 1][m - 1];
        for (int j = m - 2; j >= 0; j--) 
            der[j] = min(arr[i - 1][j], der[j + 1]);
        
        for (int j = 0; j < m; j++) {
            int IzqVal = (j - 1) >= 0 ? izq[j - 1] :
            1000000;
            int DerVal = (j + 1) < m ? der[j + 1] :
            1000000;
            arr[i][j] += min(IzqVal, DerVal);
        }
    }
    int rpta = INT_MAX;
    for (int i = 0; i < m; i++)
        rpta = min(rpta, arr[n - 1][i]);
    return rpta;
}

main(){
   vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
   cout << MFPS(v)<<endl;
}