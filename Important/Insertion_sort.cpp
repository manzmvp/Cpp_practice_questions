#include <iostream>
using namespace std;

void insertionSort(int arr[],int N){
    int key,j;
    for(int i=1;i<N;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

void printArr(int arr[],int N){
    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={5,7,1,3,9,10,9};
    int N = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,N);
    printArr(arr,N);
    
    return 0;
}