//Frequency Sort
#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[]={4,6,8,7,4,4,6,7,9};
    int size=*(&arr+1)-arr;
    int frequency[size]={0};
    for(int i=0;i<size;i++){
        if(arr[i]!=-1){
            frequency[i]++;
            for(int j=i+1;j<size;j++){
                if(arr[j]==arr[i]){
                    frequency[i]++;
                    arr[j]=-1;
                }
            }
        }
    }
    for(int i=0;i<size;i++){
        int max_at=i;
        for(int j=0;j<size;j++){
            if(frequency[j]>frequency[max_at]){
                max_at=j;
            }
        }
        for(int m=0;m<frequency[max_at];m++){
            cout<<arr[max_at]<<" ";
        }
        frequency[max_at]=0;
    }
    return 0;
}