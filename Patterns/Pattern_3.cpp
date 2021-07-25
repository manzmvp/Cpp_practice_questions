// Print the word with odd letters – PROGRAM
// Sample Output- 
// P      P   6

//  R    R    4

//   O  O     2
 
//    G       0

//   R  R  

//  A    A 

// M      M

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str="GEEKSFORGEEKS";
    int n=str.size();
    int mid=n-1;
    for(int i=0;i<n/2;i++,cout<<endl){
        for(int space=0;space<i;space++){
            cout<<" ";
        }
        cout<<str[i];
        for(int space=mid;space>0;space--){
            cout<<" ";
        }
        mid-=2;
        cout<<str[i];
    }


    for(int i=0;i<n/2;i++){
        cout<<" ";
    }
    cout<<str[n/2]<<endl;


    for(int i=(n/2)+1;i<n;i++,cout<<endl){
                mid+=2;
        for(int space=n-i-1;space>0;space--){
            cout<<" ";
        }
        cout<<str[i];
        for(int space=mid;space>0;space--){
            cout<<" ";
        }
        cout<<str[i];
    }
    return 0;
}