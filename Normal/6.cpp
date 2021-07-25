// Write a program to sort the elements in odd positions in descending order and elements in ascending order
// Eg 1: Input: 13,2,4,15,12,10,5
//         Output: 13,2,12,10,5,15,4
// Eg 2: Input: 1,2,3,4,5,6,7,8,9
//         Output: 9,2,7,4,5,6,3,8,1 
        
#include <bits/stdc++.h>
using namespace std;

void sort(int* arr,int n){
    for(int i=0;i<n;i+=2){
        int temp=0;
        int max_at=i;
        for(int j=i+2;j<n;j+=2){
            if(arr[max_at]<arr[j]){
                max_at=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[max_at];
        arr[max_at]=temp;
    }

    for(int i=1;i<n;i+=2){
    int temp=0;
    int min_at=i;
        for(int j=i+2;j<n;j+=2){
            if(arr[min_at]>arr[j]){
                min_at=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min_at];
        arr[min_at]=temp;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    sort(arr,9);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}