/* Remove unbalanced parentheses in a given expression.
    Eg.) Input  : ((abc)((de))
         Output : ((abc)(de)) 
         Input  : (a(b)))(cd)  
         Output : (a(b))(cd)
	     Input  : (a(b)))(c(d)
         Output : (a(b))(cd)
         Input  : (ab))(c(d))))
         Output : (ab)(c(d))
         Input  : (((ab)
         Output : (ab) 
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int open=0,close=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            open++;
        }
        else if(str[i]==')'){
            open--;
        }
        if(open<0){
            open=0;
            str[i]=-1;
        }
    }
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]==')'){
            close++;
        }
        else if(str[i]=='('){
            close--;
        }
        if(close<0){
            close=0;
            str[i]=-1;
        }
    }
    for(int i=0;i<str.size();i++){
        if(str[i]==-1){
            continue;
        }
        else{
            cout<<str[i];
        }
    }
    return 0;
}
