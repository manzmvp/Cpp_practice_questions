/* Save the string “WELCOMETOZOHOCORPORATION” in a two dimensional array and search for substring like “too” in the two dimensional string both from left to right and from top to bottom.
w	e	L	C	O
M	E	T	O	Z
O	H	O	C	O
R	P	O	R	A
T	I	O	n	  
And print the start and ending index as
Start index : <1,2>
End index: <3, 2>*/

#include <bits/stdc++.h>
using namespace std;
void findString(vector<vector<char>> arr, string sub){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(sub[0]==arr[i][j]){
                int k=0,m=i,n=j;
                while(j<arr[0].size() && k<sub.size()){
                    if(sub[k]==arr[m][n]){
                        k++;
                        n++;
                    }
                }
                if(k==sub.size()){
                    cout<<"Start index:"<<"<"<<i<<","<<j<<">"<<endl<<"End index:"<<"<"<<i<<","<<--n<<">"<<endl;;
                }
            }
        }
    }
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(sub[0]==arr[j][i]){
                int k=0,m=j,n=i;
                while(j<arr.size() && k<sub.size()){
                    if(sub[k]==arr[m][n]){
                        k++;
                        m++;
                    }
                }
                if(k==sub.size()){
                    cout<<"Start index:"<<"<"<<j<<","<<i<<">"<<endl<<"End index:"<<"<"<<--m<<","<<i<<">"<<endl;;
                }
            }
        }
    }
}

int main(){
    int col,row;
    char temp;
    cin>>row>>col;
    vector<vector<char>> arr(row, vector<char> (col,' '));
    cout<<"ENter"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"String"<<endl;
    string sub;
    cin>>sub;
    findString(arr,sub);
    return 0;
}