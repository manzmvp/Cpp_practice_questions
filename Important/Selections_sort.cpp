#include<iostream>  
using namespace std;  
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main()  
{  
    int arr[]={1,3,2,6,8,4,5,7};
    int min=0, min_at=0,N=8;
    for(int i=0; i<N-1; i++){
        min=arr[i];
        min_at=i;
        for(int j=i+1; j<N; j++){
            if(arr[j]<min){
                min_at=j;
                min=arr[j];
                cout<<endl<<min<<endl;
            }
        }
        swap(&arr[i],&arr[min_at]);
        cout<<endl;
        for(int i=0;i<N;i++){
            cout<<arr[i]<<" ";
        }
    }

return 0;   
}  