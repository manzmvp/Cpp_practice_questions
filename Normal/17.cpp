// Given a 2D grid of characters, you have to search for all the words in a dictionary by
// moving only along two directions, either right or down. Print the word if it occurs.
// Sample :         
// a   z  o   l 
// n   x  h   o
// v   y   i   v 
// o   r   s  e 
// Dictionary = {van, zoho, love, are, is} 
// Output: 
// zoho 
// love 
// Is 
#include <bits/stdc++.h>
using namespace std;

bool checkPresent(vector<vector<char>> arr,string str,int index,int row,int col){
    if(row<4&&col<4){
        if(arr[row][col]==str[index]){
            if(str.size()-1==index){
                if(arr[row][col]==str[index]){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(checkPresent(arr,str,index+1,row,col+1) || checkPresent(arr,str,index+1,row+1,col)){
                return 1;
            }
        }
    }
    return 0;
}

bool utilFunction(vector<vector<char>> arr,string str){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==str[0]){
                if(checkPresent(arr,str,1,i,j+1) || checkPresent(arr,str,1,i+1,j)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    vector<vector<char>> arr {{'a', 'z', 'o', 'l'}, 
                      {'n', 'x', 'h', 'o'},
                      {'v', 'y', 'i', 'v'},
                      {'o', 'r', 's', 'e' }};
    vector<string> str_ar {"van", "zoho", "love", "are", "is","zxyse"};
    for(int i=0;i<str_ar.size();i++){
        if(utilFunction(arr,str_ar[i])){
            cout<<str_ar[i]<<endl;
        }
    }
    return 0;
}