// Reverse words in a string ex: Dog barks output: god skrab.(15 marks)
#include <bits/stdc++.h>
using namespace std;

string reverse(string s){
    stack<char> stack;
    string str;
    for(int i=0;i<s.size();i++){
        stack.push(s[i]);
    }
    while(!stack.empty()){
        // cout<<stack.top();
        str.push_back(stack.top());
        stack.pop();
    }
    // cout<<"here"<<str;
    return str;
}
void printString(vector<string> v){
    for(auto itr:v){
        cout<<itr<<" ";
    }
}

void splitWords(string str){
    string s;
    vector<string> v;
    for(auto itr:str){
        if(itr==' ' || itr=='.'){
            v.push_back(reverse(s));
            cout<<s<<endl;
            s="";
        }
        else{
            s.push_back(itr);
        }
    }
    printString(v);
}

int main(){
    string s;
    getline(cin,s);
    s[0]=char(s[0] + 32);
    splitWords(s);
    return 0;
}