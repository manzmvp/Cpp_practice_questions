#include <bits/stdc++.h>

using namespace std;

void bfs(int S, int V, vector<int> arr[]){
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(S);
    visited[S]=1;
    while(!q.empty()){
        S = q.front();
        cout<<S<<" ";
        q.pop();
        for(int i=0;i<arr[S].size();i++){
            if(!visited[arr[S][i]]){
                visited[arr[S][i]]=1;                        
                q.push(arr[S][i]);
            }
        }
    }
}
        

int main(){
    int V, E, S;
    cin>>V>>E>>S;
    vector<int> arr[V];
    
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    bfs(S, V, arr);
    return 0;
}