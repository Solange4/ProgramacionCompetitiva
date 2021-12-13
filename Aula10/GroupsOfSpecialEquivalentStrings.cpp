#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

string convertir(string str) {
    string odd;
    string even;
    for(int i=0; i<str.size(); i++)
        i%2 == 0 ? odd += str[i] : even += str[i];
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    return even + odd;
}
int GroupofSpecial(vector<string>& A) {
    set<string> S;
    for(int i=0; i<A.size(); i++)
        S.insert(convertir(A[i]));
    return S.size();
}

int main(){
    vector<string> str = {"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    cout<<GroupofSpecial(str)<<endl;
}