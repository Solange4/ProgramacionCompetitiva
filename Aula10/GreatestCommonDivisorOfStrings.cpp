#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <iterator>
#include <string>
#include <regex>
using namespace std; 

int GCD(int x, int y){
     return y == 0 ? x : GCD(y, x%y);
}
    
string GCDStrings(string str1, string str2) {
    int l1 = str1.size(), l2 = str2.size();
    int gcd = GCD(l1, l2);
    string sgcd = str1.substr(0, gcd);
    regex pattern(("(" + sgcd + ")+"));
    return  regex_match(str1, pattern) && regex_match(str2, pattern) ? sgcd: "";
}

int main(){
    //Case 1
    string s1 = "ABCABC";
    string s2 = "ABC"; 
    cout<<GCDStrings(s1,s2)<<endl;
    //Case 2
    string s3 = "ABABAB";
    string s4 = "ABAB"; 
    cout<<GCDStrings(s3,s4)<<endl;
}