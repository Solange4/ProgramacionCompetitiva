#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <iterator>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    string tmp;
    vector<vector<string>> res;
    unordered_map<string, int> um;
    for (auto str: strs){
        tmp = str;
        sort(tmp.begin(), tmp.end());
        if (um[tmp]>0)  
            res[um[tmp]-1].push_back(str);
        else{
            res.push_back({str});
            um[tmp] = res.size();  
        }    
    }      
    return res;
}

int main(){
    vector<string> str = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> clusters = groupAnagrams(str);
    for( auto const& string_vec : clusters ){
        for( auto const& s : string_vec )
            cout << s << ", ";
        cout<<endl;
    }
}