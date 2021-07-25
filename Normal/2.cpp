// Three strings will be given as
// Input string 
// 1: I walk everyday in the morning.
// 2: I run everyday in the evening.
// 3: I swim everyday in the night.

// Output: 
// I everyday in the

#include <bits/stdc++.h>
using namespace std;

void splitWords(string s,vector<vector<string>> &v, int i){
    string s1="";
    for(char itr : s){
        if(itr==' '){
            v[i].push_back(s1);
            s1="";
        }
        else
            s1.push_back(itr);
    }
    v[i].push_back(s1);

}

void findIntersection(vector<vector<string>> &v){
    for(int i=0;i<v[0].size();i++){
        for(int j=0;j<v[1].size();j++){
            if(v[0][i]==v[1][j]){
                for(int k=0;k<v[2].size();k++){
                    if(v[0][i]==v[2][k]){
                        v[3].push_back(v[0][i]);
                    }
                }
            }
        }
    }
    for(auto itr:v[3]){
        cout<<itr<<" ";
    }
}

int main(){
    string s1,s2,s3;
    vector<vector<string>> v(4);
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    splitWords(s1,v,0);
    splitWords(s2,v,1);
    splitWords(s3,v,2);
    findIntersection(v);
    return 0;
}






