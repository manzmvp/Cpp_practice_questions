// . Given a String with numbers and operators. Perform the operation on the numbers in their respective order. Operator precedence need not be considered. The input string will have the numbers followed by the operators.

// Input: "12345 * + - + "
// Result: 6 [Explanation: 1 * 2 + 3 - 4 + 5 = 6]
// Input: "374291 - - * + -"
// Result: -8 [Explanation: 3 - 7 - 4 * 2 + 9 - 1 = -8]

#include <bits/stdc++.h>
using namespace std;
void evalute(char op, stack<int> &stack){
    if(op=='*'){
        int temp=stack.top();
        stack.pop();
        int temp1=stack.top();
        stack.pop();
        stack.push(char(temp*temp1));
    }
    else if(op=='+'){
        int temp=stack.top();
        stack.pop();
        int temp1=stack.top();
        stack.pop();
        stack.push(char(temp+temp1));

    }
    else if(op=='-'){
        int temp=stack.top();
        stack.pop();
        int temp1=stack.top();
        stack.pop();
        stack.push(char(temp-temp1));
    }
}

int main(){
    string s;
    string num;
    string op;
    stack<int> stack;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*'||s[i]=='+'||s[i]=='-'){
            op.push_back(s[i]);
        }
        else{
            num.push_back(s[i]);
        }
    }
    for(int i=num.size()-1;i>=0;i--){
        stack.push(num[i]-'0');
    }
    for(int i=0;i<op.size();i++){
        evalute(op[i],stack);
    }
    cout<<stack.top();
    return 0;
}