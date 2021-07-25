// Print the following pattern
//    1  
//   3 2
//  6 5 4
// 10 9 8 7
// 10 9 8 7 
//  6 5 4 
//   3 2 
//    1
#include <bits/stdc++.h>
using namespace std;
int main(){
    int num=0;
    for(int i=1;i<=4;i++,cout<<"\n"){
        num=num+i;
        for(int space=1;space<=4-i;space++){
            cout<<" ";
        }
        for(int j=num;j>num-i;j--){
            cout<<j<<" ";
        }  
    }
    for(int i=4;i>=1;i--,cout<<"\n"){
        for(int space=1;space<=4-i;space++){
            cout<<" ";
        }
        for(int j=num;j>num-i;j--){
            cout<<j<<" ";
        }  
        num=num-i;
    }
    return 0;
}