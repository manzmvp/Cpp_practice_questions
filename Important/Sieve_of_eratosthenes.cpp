#include <bits/stdc++.h>
using namespace std;
int main(){
    int N=9;
    int arr[N+1];
    memset(arr,0,sizeof(arr));
    for(int i=2;i<=sqrt(N),arr[i]==0;i++){
        for(int j=i*i; j<=N;j=j+i){
            arr[j]=1;
        }
    }
    for(int i=2;i<=N;i++){
        if(arr[i]==0)
            cout<<i<<" ";
    }
    return 0;
}