// While typing, it is possible to press a key long enough that it could get typed more than once. 
// Given two strings A and B, check if B could be a typed version of A.
// Input 1:  
// A = anime  
// B = aanimeee​
// Output 1:  
// True  
// Input 2:  
// A = Limcee  
// B = Limmcce​
// Output 2:  
// False 
#include <bits/stdc++.h>
using namespace std;

bool checkTypo(string str1,string str2){
    char memory;
    int i=0;
    for(int j=0;j<str2.size();j++){
        if(str2[j]==str1[i]){
            memory=str1[i];
            if(i<(str1.size()-1))
                i++;
        }
        else if(str2[j]==memory){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string str1="anime";
    string str2="aaniiiiiimmmmeee";
    if(checkTypo(str1,str2)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}