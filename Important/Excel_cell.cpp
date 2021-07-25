// 1) To output the given string for the given input which is an integer.
// Input: 1
// Output: A
// Input: 26
// Output: Z
// Input : 27
// Output: AA
// Input: 28:
// Output: AB
// Input: 1000
// Output: ALL
//1*26^2+12*26^1+12*26^0

#include <bits/stdc++.h>
using namespace std;
int main(){
    int num,rem,qout;
    vector<char> str;
    cin>>num;
    while(num!=0){
        rem = num%26;
        if(rem==0){
            str.push_back('Z');
            num=(num/26)-1;
        }
        else{
            str.push_back(char(64+rem));
            num/=26;
        }
    }
    for(int i=str.size()-1;i>=0;i--){
        cout<<str[i];
    }
    return 0;
}