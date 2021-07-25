#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};
struct queuenode{
    struct point p;
    int dist;
};
int isPointValid(int x, int y,int row, int col,vector<vector<int>> arr,vector<vector<int>> visited){
    return x<row && y<col && x>=0 && y>=0 && arr[x][y] && !visited[x][y];
}
int rowno[]={-1,0,1,0};
int colno[]={0,1,0,-1};
int shortestPath(vector<vector<int>> arr, point src, point dest,int row,int col){
    vector<vector<int>> visited(row, vector<int>(col,0));
    queue<queuenode> q;
    queuenode s;
    s.p = src;
    s.dist=0;
    q.push(s);
    visited[src.x][src.y]=1; 
    while(!q.empty()){
        queuenode curr=q.front();
        if(curr.p.x==dest.x&&curr.p.y==dest.y){
            return curr.dist;
        }
        q.pop();
        for(int i=0; i<4;i++){
            int adjrow = curr.p.x + rowno[i];
            int adjcol = curr.p.y + colno[i];
            if(isPointValid(adjrow,adjcol,row,col,arr,visited)){
                visited[adjrow][adjcol]=1;
                queuenode adjnode = {{adjrow,adjcol},curr.dist+1};
                q.push(adjnode);
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> arr=    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
    point source = {0, 0};
    point dest = {3, 4};
    int row=9;
    int col=10;
    int dist = shortestPath(arr, source, dest,row,col);
 
    if (dist != -1)
        cout << "Shortest Path is " << dist ;
    else
        cout << "Shortest Path doesn't exist";
 

}