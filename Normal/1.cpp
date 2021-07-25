// Given a matrix M of dimension A x B containing 0’s and 1’s, find out the number of positions at which the value is 1 and other elements in its corresponding rows and columns are all 0.
// Input 1:  
// A = 3, B = 3  
// 100  
// M = 001  
// 010  
// Output 1:  
// 3  
// Input 2:  
// A = 3, B = 3  
// 100  
// M = 001  
// 100  
// Output 2:  
// 1 

#include <bits/stdc++.h>
using namespace std;

bool checkUnique(int i, int j, int row_size, int col_size, int arr[3][3]){
    for(int row=0;row<row_size;row++){
        if(arr[row][j]==1 && row!=i){
            return false;
        }
    }
    for(int col=0;col<col_size;col++){
        if(arr[i][col]==1 && col!=j){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[3][3]={{1,0,0},{0,0,1},{1,0,0}};
    int count=0;
    int row_size=sizeof(arr)/sizeof(arr[0]);
    int col_size=sizeof(arr[0])/sizeof(int);
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            if(arr[i][j]==1){
                if(checkUnique(i,j,row_size,col_size,arr)){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}