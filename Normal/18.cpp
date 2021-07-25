// GIven 2 huge numbers as seperate digits, store them in array
// and process them and calculate the sum of 2 numbers and store
// the result in an array and print the sum.

// Input:
// Number of digits:12
// 9 2 8 1 3 5 6 7 3 1 1 6
// Number of digits:9
// 7 8 4 6 2 1 9 9 7
// Output :
// 9 2 8 9 2 0 2 9 5 1 1 3
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a {1,5,0,9};
    vector<int> b {2,0,4};
    vector<int> c;
    int i=a.size()-1;
    int j=b.size()-1;
    int carry=0;
    while(i>=0 || j>=0){
        if(i>=0 && j>=0){
            c.push_back((a[i]+b[j]+carry)%10);
            carry = (a[i]+b[j]+carry)/10;
            i--;
            j--;
        }
        else if(i>=0){
            c.push_back((a[i]+carry%10));
            carry = (a[i]+carry)/10;
            i--;
        }
        else if(j>=0){
            c.push_back((b[j]+carry)%10);
            carry = (b[j]+carry)/10;
            j--;
        }
    }
    for(int i=c.size()-1;i>=0;i--){
        cout<<c[i]<<" ";
    }
    return 0;
}