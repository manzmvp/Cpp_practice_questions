// Help john to find new friends in social network
// Input:
// 3
// Mani 3 ram raj guna
// Ram 2 kumar Kishore
// Mughil 3 praveen Naveen Ramesh

// Output:
// Raj guna kumar Kishore praveen Naveen Ramesh

#include <bits/stdc++.h>
using namespace std;

int main(){
    int c;
    vector<string> friends;
    vector<string> friendsof;
    cin>>c;
    for(int i=1;i<=c;i++){
        string f;
        cin>>f;
        friends.push_back(f);
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            string m;
            cin>>m;
            friendsof.push_back(m);
        }
    }
    for(int i=0;i<friendsof.size();i++){
        int flag=0;
        for(int j=0;j<friends.size();j++){
            if(friendsof[i]==friends[j]){
                flag=1;
            }
        }
        if(flag==0){
            cout<<friendsof[i]<<" ";
        }
    }
    return 0;
}