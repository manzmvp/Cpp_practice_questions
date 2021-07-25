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

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int small_at = low-1;
    for(int j=low; j<=high-1; j++){
        if(arr[j]<pivot){
            small_at++;
            swap(&arr[small_at],&arr[j]);
        }
    }
    swap(&arr[small_at+1],&arr[high]);
    return (small_at+1);
}

void quickSort(int arr[], int low,int high){
    if(low<high){
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main()
{
    int arr[]={9,8,7,6,5,4,3,2,1};
    int N = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,N-1);
    printArr(arr,N);
    
    return 0;
}