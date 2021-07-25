// If n=6, then the pattern should be like this :
// 666666
// 655556
// 654456
// 654456
// 655556
// 666666
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num=n;
    int size=n;
    int arr[n][n]={0};
    for(int i=0;i<n;i++){
        int a=i,b=i;
        while(b<size){
            arr[a][b]=num;
            b++;
        }
        b--;
        while(a<size){
            arr[a][b]=num;
            a++;
        }
        a--;
        while(b>=i){
            arr[a][b]=num;
            b--;
        }
        b++;
        while(a>=i){
            arr[a][b]=num;
            a--;
        }
        num--;
        size--;

    }
    for(int i=0;i<n;i++,cout<<endl){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
    }
    return 0;
}