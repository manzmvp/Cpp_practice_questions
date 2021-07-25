#include <bits/stdc++.h>
using namespace std;

void longestSubsequence(string s1, string s2, int l1, int l2){
    int dp[l2+1][l1+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=l2;i++){
        for(int j=0;j<=l1;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[j-1]==s2[i-1])
                dp[i][j]=1+dp[i-1][j-1];
            else   
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<< dp[l2][l1]<<endl;
}

int main(){
    string s1="abc";
    string s2="ac";
    int l1=s1.length();
    int l2=s2.length();
    longestSubsequence(s1,s2,l1,l2);
    return 0;
}