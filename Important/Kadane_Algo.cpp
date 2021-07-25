#include <bits/stdc++.h>
using namespace std;

int kadaneAlgo(int arr[],int N){
    int max_curr,max_global;
    max_curr=arr[0];
    max_global=arr[0];
    for(int i=1;i<N;i++){
        max_curr = max(arr[i],max_curr+arr[i]);
        if(max_curr>max_global){
            max_global=max_curr;
        }
    }
    return max_global;
}

int main(){
    int arr[]={5, -3, 4, -1, 2, 6, 7, -8};
    // cout<<"h";
    int size = sizeof(arr)/sizeof(arr[0]);
    int a=kadaneAlgo(arr,size);
    cout<<a;
    return 0;
}