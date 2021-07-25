#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int t =*a;
    *a=*b;
    *b=t;
}
void printArr(int arr[],int N){
    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int arr[],int N){
    int i=--N;
    while(i){
        for(int j=0; j<=i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
        i--;
    }
}

int main()
{
    int arr[]={5,7,1,3,9,10,9};
    int N = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,N);
    printArr(arr,N);
    
    return 0;
}