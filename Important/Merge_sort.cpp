#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m, int r){
    int l1=0,l2=0;
    int s1=m-l+1,s2=r-m;
    int arr1[s1],arr2[s2];
    for(int i=0;i<s1;i++)
        arr1[i]=arr[l+i];
    for(int i=0;i<s2;i++)
        arr2[i]=arr[m+i+1];

    while(l1<s1 && l2<s2){
        if(arr1[l1]<=arr2[l2]){
            arr[l]=arr1[l1];
            l1++;
            l++;
        }
        else{
            arr[l]=arr2[l2];
            l2++;
            l++;
        }
    }
    while(l1<s1){
        arr[l]=arr1[l1];
        l1++;l++;
    }
    while(l2<s2){
        arr[l]=arr2[l2];
        l2++;l++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+(r-l)/2);
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[]={10, 8, 4, 1, 88, 6};
    int size=*(&arr+1) - arr;
    mergeSort(arr,0,size-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}