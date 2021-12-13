#include<iostream>
#include<stack>
#include <vector>
#include <string>
using namespace std;

int scoreOfParentheses(string parentesis) {
    int rpta = 0;
    stack <int> pila;
    for(int i = 0; i < parentesis.size(); i+=1){
        if(parentesis[i] == '(')
            pila.push(-1);
        else{
            if(pila.top() == -1){
               pila.pop();
               pila.push(1);
            }
            else{
                int temp = 0;
                while(pila.top() != -1){
                    temp += pila.top();
                    pila.pop();
                }
                temp *= 2;
                pila.pop();
                pila.push(temp);
            }
        }
    }
    while(!pila.empty()){
        rpta += pila.top();
        pila.pop();
    }
    return rpta;
}
main(){
    cout << scoreOfParentheses("()")<<endl;
    cout << scoreOfParentheses("(())")<<endl;
    cout << scoreOfParentheses("()()")<<endl;
    cout << scoreOfParentheses("(()(()))")<<endl;
}