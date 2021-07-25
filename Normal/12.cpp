// Given two integers a and b, the task is to add them to get c. After that remove zeroes from a, b and c and check for modified values if a + b = c then return “YES” else return “NO”.
// Examples: 
 // Input: a = 101, b = 102 
// Output: YES 
// 101 + 102 = 203. 
// After removing all zeroes from a, b and c, a = 11, b = 12 and c = 23 
// Now check if a + b = c i.e. 11 + 12 = 23 . So print Yes.
// Input: a = 105, b = 108 
// Output: NO 
// After removing all zeroes a + b!= c, therefore the output is NO. 
#include <bits/stdc++.h>
using namespace std;

int reverse(int a){
    int rem=0;
    while(a){
        rem*=10;
        rem+=a%10;
        a/=10;

    }
    return rem;
}


int removeZero(int a){
    int rem=0;
    while(a){
        if(a%10==0){
            a/=10;
            continue;
        }
        rem*=10;
        rem+=a%10;
        a/=10;

    }
    return reverse(rem);
}

int main(){
    int a,b,c;
    cin>>a>>b;
    c=a+b;
    a=removeZero(a);
    cout<<a<<endl;
    b=removeZero(b);
    cout<<b<<endl;
    c=removeZero(c);
    cout<<c<<endl;
    if(c==a+b){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}