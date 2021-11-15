#include<iostream>
#include<stack>
#include <vector>
#include <string>
using namespace std;

int Minimum(string p){
    int temp = 0;
    int rpta = 0;
    for (int i = 0; i < p.length(); ++i) {
        temp += p[i] == '(' ? 1 : -1;
        if (temp == -1) {
            rpta += 1;
            temp += 1;
        }
    }
    return temp + rpta;
}
 
int main(){
    string p1 = "())";
    cout << Minimum(p1)<<endl; //1
    string p2 = "(()))(";
    cout << Minimum(p2)<<endl; //2
    string p3 = "(((";
    cout << Minimum(p3)<<endl; //3
    string p4 = "()))((";
    cout << Minimum(p4)<<endl; //4 
    return 0;
}