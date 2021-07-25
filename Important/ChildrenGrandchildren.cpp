// Assume a two dimensional string array. Each array contains child and father details. '0'th
// element is the child and '1'st is the parent. Write a program to accept a name and find the
// number of children and grand children he has. Don't use any brute force methods.
// Assume names are unique.
// Example:
// Data:
// [
// [Surya, Sivakumar],
// [Karthi, Sivakumar],
// [Sivakumar, Rakkaiya],
// [Dev, Surya],
// [Umayaal, Karthi],
// [Diya, Surya],
// [Prabu, Sivaji],
// [Vikram, Prabu]
// ]
// Input: Surya, 1 // 1 indicates the number of children Surya has
// Output: 2
// Input: Karthi, 1
// Output: 1
// Input: Sivakumar, 2 // 2 indicates the number of grandchildren Sivakumar has
// Output: 3

//13:36


#include <bits/stdc++.h>
using namespace std;

int findNumOfChildren(string name, vector<vector<string>>arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i][1]==name){
            // cout<<arr[i][0];
            count++;
        }
    }
    return count;
}

int findNumOfGrandChildren(string name, vector<vector<string>>arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i][1]==name){
            count+=findNumOfChildren(arr[i][0],arr);
        }
    }
    return count;
}
int main(){
    vector<vector<string>> arr={{"Surya", "Sivakumar"},{"Karthi", "Sivakumar"},{"Sivakumar", "Rakkaiya"},{"Dev", "Surya"},{"Umayaal", "Karthi"},{"Diya", "Surya"},{"Prabu", "Sivaji"},{"Vikram", "Prabu"}};
    string name;
    int op;
    cin>>name>>op;
    if(op==1){
        cout<<findNumOfChildren(name,arr)<<endl;
    }
    else{
        cout<<findNumOfGrandChildren(name,arr)<<endl;
    }
    return 0;
}