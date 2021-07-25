#include <bits/stdc++.h>
using namespace std;

bool matchPattern(string str1, string str2){
    int m=str1.size(),n=str2.size();
    bool arr[m+1][n+1];
    memset(arr,false,sizeof(arr));
    arr[0][0]=true;
    for(int i=1;i<n;i++){
        if(str2[i-1]=='*'){
            arr[0][i]=arr[0][i-1];
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str2[j-1]=='*'){
                arr[i][j]=arr[i][j-1] || arr[i-1][j];
            }
            else if(str1[i-1]==str2[j-1] || str2[j-1]=='?'){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=false;
            }
        }
    }
    return arr[m][n];

}

int main(){
    string str1="baaabab";
    string str2="*****ba***?**ab";
    if(matchPattern(str1,str2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}