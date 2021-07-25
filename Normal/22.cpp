// Given bigger NxN matrix and a smaller MxM matrix print TRUE if the smaller matrix can be found in the bigger matrix else print FALSE
// Input:
// 3
// 4 5 9
// 1 3 5
// 8 2 4
// 2
// 3 5
// 2 4
// Output : True

// Input:
// 3
// 4 5 9
// 1 3 5
// 8 2 4
// 2
// 4 5
// 1 4
// Output : False
#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> arr1, vector<vector<int>> arr2,int row,int col){
    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<arr2[0].size();j++){
            if(arr1[i+row][j+col]!=arr2[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool utilFunc(vector<vector<int>> arr1, vector<vector<int>> arr2){
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1[0].size();j++){
            if(arr1[i][j]==arr2[0][0]){
                if(check(arr1,arr2,i,j)){
                    cout<<"Row:"<<i<<endl<<"Col:"<<j<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    vector<vector<int>> arr1 {{4, 5, 9},
                              {1, 3, 5},
                              {8, 2, 4}};
    vector<vector<int>> arr2 {{1, 3},
                              {8, 2}};    
    
    if(utilFunc(arr1,arr2)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    
    return 0;
}