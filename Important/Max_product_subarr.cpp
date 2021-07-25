// 1. Array have multiple integers(+&-)
// You have to calculate maximum multiplication of continuous

// A=1 2 3 -4 3 -1
// Ans=72(1 2 3-4 3 -1)

#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,-4,3,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_curr=arr[0],global_max=arr[0],min_curr=arr[0],flag=0;
    for(int i=1;i<n;i++){
        if(arr[i]==0){
            max_curr=1;
            min_curr=1;
            flag=1;
        }
        else if(arr[i]>0){
            max_curr=max_curr*arr[i];
            min_curr=min(min_curr*arr[i],1);
        }
        else{
            int temp=max_curr;
            max_curr=max(min_curr*arr[i],1);
            min_curr=temp*arr[i];
        }
        if(max_curr>global_max){
            global_max=max_curr;
        }
    }
    if(flag==0 && global_max==0){
        return 0;
    }
    cout<<global_max;
    return 0;
}