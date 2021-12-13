#include<iostream>
#include<stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> min;
    void push(int x) {
        s.push(x);
        if(min.empty()||x<=min.top())
            min.push(x);
    }
    void pop() {
        if(s.top()==min.top())
            min.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return min.top();
    }
    void imprimir(){
        while (!s.empty()) {
            cout <<s.top()<<endl;
        s.pop();
    }        
    }
};
int main(){
    MinStack s;
    int instrucciones;
    cin>>instrucciones;
    for (int i = 0; i < instrucciones; i++){
        string instruccion;
        cin>>instruccion;
        if(instruccion=="PUSH"){
            int num;
            cin>>num;
            s.push(num);
        }
        else if(instruccion=="MIN")
            cout<<s.getMin()<<endl;
        else if(instruccion=="POP")
            s.pop();
        else
            break;
    }
    return 0;
    //s.imprimir();
    
}