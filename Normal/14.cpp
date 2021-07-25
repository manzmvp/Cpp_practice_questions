// Given an array as input, The condition is if the number is repeated you must add the number and put the next index value to 0. If the number is 0 print it at the last.
// 	Example: Eg: arr[] = { 0, 2, 2, 2, 0, 6, 6, 0, 8}
// 			Output: 4 2 12 8 0 0 0 0 0 .

#include <bits/stdc++.h>
using namespace std;

int findZero(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={0,2,2,2,0,6,6,0,8};
    int zero_at;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            continue;
        }
        else if(arr[i]==arr[i+1]){
            zero_at = findZero(arr);
            arr[zero_at]=arr[i]*2;
            arr[i]=0;
            arr[i+1]=0;
        }
        else{
            zero_at = findZero(arr);
            if(zero_at<i){
                arr[zero_at]=arr[i];
                arr[i]=0;
            }
        }
    }
    for(auto i:arr){
        cout<<i<<",";
    }
    return 0;
}