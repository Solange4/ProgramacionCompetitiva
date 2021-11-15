#include<iostream>
#include<stack>
#include <vector>
#include <string>
using namespace std;


int evalRPN(vector<string> &tokens){
    stack<int> nums;
    for (int i = 0; i < tokens.size(); i++) {
        string s = tokens[i];
        if (isdigit(s[0]) || s.size() > 1) {
            nums.push(stoi(s));
            continue;
        }
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        if (s == "+")
            nums.push(a+b);
        else if (s == "-") 
            nums.push(b-a);
        else if (s == "*") 
            nums.push(a*b);
        else 
            nums.push(b/a);
    }
    return nums.top();
}
main(){
    vector<string> num1 = {"2","1","+","3","*"};
    cout<<evalRPN(num1)<<endl; //9
    vector<string> num2 = {"4","13","5","/","+"};
    cout<<evalRPN(num2)<<endl; //6
    vector<string> num3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(num3)<<endl; //22
}