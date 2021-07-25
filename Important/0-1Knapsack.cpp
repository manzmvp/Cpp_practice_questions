#include <bits/stdc++.h>
using namespace std;
int main(){
    int N=3, W=3;
    int values[]={1,2,3};
    int weights[]={5,2,1};
    int dp[N+1][W+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(weights[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }   
    for(int i=0;i<=N;i++,cout<<endl){
        for(int j=0;j<=W;j++){    
            cout<<dp[i][j]<<" ";}}
            cout<<dp[N][W]<<endl;
    return 0;
}
     
