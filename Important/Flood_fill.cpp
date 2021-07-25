#include <bits/stdc++.h>
using namespace std;
int ROW=3,COL=3;
int isSafe(vector<vector<int>> &arr,int row,int col,int num){
    if(row<ROW && col<COL && row>=0 && col>=0 && arr[row][col]==num){
        return 1;
    }
    return 0;
}

void bfs(vector<vector<int>> &arr, int row, int col, int color){
    int old_color=arr[row][col];
    arr[row][col]=color;
    if(isSafe(arr,row-1,col,old_color)){
            bfs(arr,row-1,col,color);
    }
    if(isSafe(arr,row,col+1,old_color)){
            bfs(arr,row,col+1,color);
    }
    if(isSafe(arr,row+1,col,old_color)){
            bfs(arr,row+1,col,color);
    }
    if(isSafe(arr,row,col-1,old_color)){
            bfs(arr,row,col-1,color);
    }


}

int main(){
    vector<vector<int>> arr={{1,1,1},{1,1,0},{1,0,1}};
    bfs(arr,1,1,2);
    for(int i=0; i<ROW; i++,cout<<endl){
        for(int j=0;j<COL;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}