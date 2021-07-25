// Write a program to print the below pattern
// for n = 6
// 	1	7	12	16	19	21
// 	2	8	13	17	20
// 	3	9	14	18	
// 	4	10	15
// 	5	11	
// 	6 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][n]={0};
    int size=n,row=n,num=1;
    for(int i=0;i<n;i++){
        row=0;
        while(row<size){
            arr[row][i]=num;
            num++;
            row++;
        }
        size--;
    }
    for(int i=0;i<n;i++,cout<<endl){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                cout<<"  ";
            }
            else{
                cout<<arr[i][j]<<" ";
            }
        }
    }
    return 0;
}