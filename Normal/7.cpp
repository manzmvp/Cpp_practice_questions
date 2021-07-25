// Given an array, fill the alternate duplicate elements by 0.
// Input 1:  
// 2 2 2 2  
// Output 1:  
// 2 0 2 0   
// Input 2:  
// 1 2 2 5 6 9 5 2  
// Output 2:  
// 1 2 0 5 6 9 0 2 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1, 2, 2, 5, 6, 9, 5, 2};
    int size=*(&arr+1) - arr;
    unordered_map<int,int> map;
    for(int i=0;i<size;i++){
        if(map.find(arr[i])!=map.end()){
            if(map[arr[i]]==1){
                map[arr[i]]=0;
                arr[i]=0;
            }
            else{
                map[arr[i]]=1;
            }
        }
        else{
            map[arr[i]]=1;
        }
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}