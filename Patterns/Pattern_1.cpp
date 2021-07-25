// They will give any word as input for ex: WATER. This should be printed as

    //     T
    //    TE
    //   TER
    //  TERW
    // TERWA
//     Input: PROGRAM
// Given an odd length word which should be printed from the middle of the word.
// Output:
//               G
//             GR
//           GRA
//        GRAM
//      GRAMP
//    GRAMPR
// GRAMPRO
#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k;
    string st="MANOJK"; //size 5
    int end = st.size();
    int mid= end%2 ? (end/2)+1:end/2;
    int ptr=mid;
    for( i=1;i<=5;i++){
    ptr=mid;
    for( j=5;j>i;j--){
        cout<<" ";
    }
    for( k=1;k<=j;k++){
        cout<<st[ptr-1];
        ptr++;
        if(ptr>end){
            ptr=1;
        }
    }
    cout<<endl;
    }
    return 0;
}