// Given 2 strings A and B, check if swapping 2 characters only once in string ‘A’ makes the string equal to ‘B’.
// Input:  
// A = flrweo    
// B = flower​
// Output:  
// True 
#include<bits/stdc++.h>
using namespace std;

string compStr(string str1, string str2){
    if(str1.size()!=str2.size()){
        return "false";
    }
    vector<char> st1,st2;
    for(int i=0;i<str1.size();i++){
        if(str1[i]!=str2[i]){
            st1.push_back(str1[i]);
            st2.push_back(str2[i]);
        }
    }
    for(auto i:st2){
        cout<<i<<endl;
    }
    if(st1.size()==st2.size()){
        if(st1.size()==0){
            return "true";
        }
        else if(st1.size()==2){
            if(st1[0]==st2[1] && st2[0]==st1[1]){
                return "true";
            }
        }
        else{
            return "false";
        }
    }
    return "false";
}


int main(){
    string str1="Manoj";
    string str2="Manjo";
    cout<<compStr(str1,str2);
    return 0;
}