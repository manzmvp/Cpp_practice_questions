#include <bits/stdc++.h>
using namespace std;

void dfsutil(int i,vector<int> &visited, vector<int> arr[]){
    visited[i]=1;
    cout<<i<<" ";
    for(int u=0;u<arr[i].size();u++){
        if(visited[arr[i][u]] == 0){
            dfsutil(arr[i][u],visited,arr);
        }
    }
}

void dfs(int V, vector<int> arr[]){
    vector<int> visited(V,0);
    // for(int i=0;i<V;i++){
    //     if(visited[i]==0){
            dfsutil(0,visited,arr);
            // }
    // }
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<int> arr[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(V, arr);
    return 0;
}

