#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparar(pair<int,int> &a, pair<int,int> &b){
    return (a.second < b.second);
}
void sumTwoValues(vector<pair<int,int>> &array, int n, int x){
    sort(array.begin(), array.end(),comparar);
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
        cout <<array[i].first+1<<" "<<array[j].first+1<<endl;
    else
        cout << "IMPOSSIBLE" << endl;   
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> array; 
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        array.push_back({i,a});
    }
    sumTwoValues(array, n, x);

    return 0;
}