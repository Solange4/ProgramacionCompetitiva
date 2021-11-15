#include<iostream>
#include<stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int op(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
void InfixtoPostfix(string expresion) {
    stack<char> temp;
    string rpta;
    for(int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            rpta += c;
        else if(c == '(')
            temp.push('(');
        else if(c == ')') {
            while(temp.top() != '('){
                rpta += temp.top();
                temp.pop();
            }
            temp.pop();
        }
        else {
            while(!temp.empty() && op(expresion[i]) <= op(temp.top())) {
                rpta += temp.top();
                temp.pop(); 
            }
            temp.push(c);
        }
    }
    while(!temp.empty()) {
        rpta += temp.top();
        temp.pop();
    }
    cout << rpta << endl;
}

int main() {
    int casos;
    cin>>casos;
    for (int i = 0; i < casos; i++){
        string expresion;
        cin>>expresion;
        InfixtoPostfix(expresion);
    }    
    return 0;
}