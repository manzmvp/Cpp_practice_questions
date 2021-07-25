// Form a number system with only 3 and 4. 
// Find the nth number of the number system. Eg.) 
// The numbers are: 3, 4, 33, 34, 43, 44, 333, 334, 343, 344, 433, 434, 443, 444, 3333, 3334, 3343, 3344, 3433, 3434, 3443, 3444 ….

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1]={0};
    arr[0]=3;
    arr[1]=4;
    int j=2;
    for(int i=0;i<n;i++){
        arr[j]=(arr[i]*10)+3;
        j++;
        arr[j]=(arr[i]*10)+4;
        j++;
        if(j>=n-1){
            cout<<arr[n-1];
            break;
        }
    }
    return 0;
}
