// Sample Input- 
// 2 
// Hacker 
// Rank 
// Sample Output- 
// Hce akr 
// Rn ak

#include <bits/stdc++.h>
using namespace std;

void print(string s){
    for(int i=0;i<s.size();i+=2){
        cout<<s[i];
    }
    cout<<" ";
    for(int i=1;i<s.size();i+=2){
        cout<<s[i];
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    string ar[N];
    for(int i=0;i<N;i++){
        cin>>ar[i];
    }
    for(int i=0;i<N;i++){
        print(ar[i]);
    }

    return 0;
}