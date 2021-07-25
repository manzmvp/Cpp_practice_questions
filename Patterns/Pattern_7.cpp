// Print the given pattern:
// Input:
// N= 3, M=3
// Output:
// X X X
// X 0 X
// X X X

// Input:
// N=4 M=5
// Output:
// X X X X
// X 0 0 X
// X 0 0 X
// X 0 0 X
// X X X X

// Input:
// N=6 M=7
// X X X X X X
// X 0 0 0 0 X
// X 0 X X 0 X
// X 0 X X 0 X
// X 0 X X 0 X
// X 0 0 0 0 X
// X X X X X X
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    char arr[m][n];
    int a,b,row=m,col=n;
    char turn;
    int i=0;
    int j=max(row,col)%2==0 ? max(row,col)/2 : (max(row,col)/2)+1;
    while(i<j){
        if(i%2==0 || i==0){
            turn='X';
        }
        else{
            turn='0';
        }
        a=i,b=i;
        while(b<col){
            arr[a][b]=turn;
            b++;
        }
        b--;
        while(a<row){
            arr[a][b]=turn;
            a++;
        }
        a--;
        while(b>=i){
            arr[a][b]=turn;
            b--;
        }
        b++;
        while(a>=i){
            arr[a][b]=turn;
            a--;
        }
        row--;
        col--;
        i++;
    }
    for(int i=0;i<m;i++,cout<<endl){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}