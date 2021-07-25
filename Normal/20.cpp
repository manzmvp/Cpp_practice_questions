// You’re given a number n. If write all the numbers from 1 to n in a paper, we have to find the number of characters 
// written on the paper.For example if n=13, the output should be 17 if n = 101, the output should be 195
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num=0;
    for(int  i=1;i<=n;i*=10){
        num+=(n-(i-1));
    }
    cout<<num;
    return 0;
}