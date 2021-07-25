// Write a program to give the following output for the given input

// Eg 1: Input: a1b10
//        Output: abbbbbbbbbb
// Eg: 2: Input: b3c6d15
//           Output: bbbccccccddddddddddddddd
// The number varies from 1 to 99.
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int i=0;i<str.size();){
        char times;
        if(i+2<str.size()){
            if(str[i+2]>='0' & str[i+2]<='9'){
                for(int j=1;j<=(10*(str[i+1]-'0')+(str[i+2]-'0'));j++)
                    cout<<str[i];
                i+=3;
            }
            else{
                for(int j=1;j<=((str[i+1]-'0'));j++)
                    cout<<str[i];
                i+=2;
            }
        }
        else{
            for(int j=1;j<=(str[i+1]-'0');j++)
                cout<<str[i];
            i+=2;
        }
    }
    return 0;
}