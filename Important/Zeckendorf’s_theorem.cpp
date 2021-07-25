// Write a program to represent a number(positive integer) as the sum of
// one or more distinct Fibonacci numbers in such a way that the sum does
// not include any two consecutive Fibonacci numbers.
// Example:
// Input: 64
// Output: 55+8+1
// "55+5+3+1" is wrong since 5 and 3 are consecutive Fibonacci numbers.
// Input: 50
// Output: 34+13+3

#include <bits/stdc++.h>
using namespace std;


int nextElement(int N){
    if(N==0||N==1){
        cout<<N;
        return N;
    }
    int f1=0,f2=1,f3=1;
    while(f3<=N){
        f1=f2;
        f2=f3;
        f3=f1+f2;
    }
    cout<<f2<<"+";
    return f2;
}
int main(){
    int N;
    cin>>N;
    while(N>0){
        int f= nextElement(N);
        N=N-f;
    }
    return 0;
}