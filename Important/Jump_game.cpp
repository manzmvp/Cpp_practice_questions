#include <bits/stdc++.h>
// {4,2,0,0,1,5,6,7}
using namespace std;
int main(){
    int arr[]={4,2,0,1,1,5,6,7};
    int size=sizeof(arr)/sizeof(arr[1]);
    int reachable = 0;
    for(int i=0;i<size;i++){
        if(i<reachable){
            cout<<"False";
            return false;
        }
        reachable=max(i+arr[i],reachable);
    }
    cout<<"True";
    return true;

}   