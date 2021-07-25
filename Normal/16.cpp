// Using Recursion reverse the string such as
// Eg 1: Input: one two three
//       Output: three two one
// Eg 2: Input: I love india
//       Output: india love I 

#include <bits/stdc++.h>
using namespace std;

string reverse(string str,int st,string &ans){
    string word;
    for(int i=st;i<str.size();i++){
        if(str[i]==' '){
            return reverse(str,i+1,ans)+" "+word;
            // return(ans+" "+word);
        }
        else if(i==str.size()-1){
            word.push_back(str[i]);
            return word;
        }
        else{
            word.push_back(str[i]);
        }
    }
    return ans;
}

int main(){
    string str,ans;
    getline(cin,str);
    cout<<reverse(str,0,ans);
    return 0;
}
