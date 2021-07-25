#include <bits/stdc++.h>
using namespace std;

void combination(string str,char arr[],int r,int i,int j){
    if(j==r){
        for(int k=0;k<r;k++){
            cout<<arr[k];
        }
        cout<<endl;
        return;
    }
    if(i>=str.size()){
        return;
    }
    arr[j]=str[i];
    combination(str,arr,r,i+1,j+1);

    combination(str,arr,r,i+1,j);
}

void combinationUtil(string str,int r){
    char arr[r];
    combination(str,arr,r,0,0);
}

int main(){
    string str;
    cin>>str;
    int r;
    cin>>r;
    combinationUtil(str,r);
    return 0;
}
