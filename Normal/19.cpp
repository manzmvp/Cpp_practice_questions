// Write a program to rotate an n*n matrix 90,180,270,360 degree.
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rotateBy90(vector<vector<int>> &arr,int n){
    vector<vector<int>> ans(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][i]=arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int temp=ans[i][j];
            ans[i][j]=ans[i][n-1-j];
            ans[i][n-1-j]=temp;

        }
    }
    return ans;
}

vector<vector<int>> rotateBy180(vector<vector<int>> &arr,int n){
    vector<vector<int>> ans(n,vector<int> (n,0));
    ans=rotateBy90(arr,n);
    ans=rotateBy90(ans,n);
    return ans;
}
    vector<vector<int>> ans;

vector<vector<int>> rotateBy270(vector<vector<int>> &arr,int n){
    vector<vector<int>> ans(n,vector<int> (n,0));
    ans=rotateBy180(arr,n);
    ans=rotateBy90(ans,n);
    return ans;
}

int main(){
    int n=3,m=3;
    vector<vector<int>> arr {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans(n,vector<int> (n,0));
    ans=rotateBy270(arr,arr.size());
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}