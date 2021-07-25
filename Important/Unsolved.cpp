// 3
// KINGSTRING
// KINGING
// GIFT
// GIFT
// AWESOME
// AWSOE
#include <bits/stdc++.h>
using namespace std;
bool check(string s1,string s2){
    for (int i = 0; i < s1.size(); i++)
        for (int len = 1; len <= s1.size() - i; len++)
            string sub = s1.substr(i, len);
            string temp = s1;
            temp.replace(sub,"");
    // String helloWorld = "Hello World!";
    // String hellWrld = helloWorld.replace("o","");
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<string> sol(n);
    vector<pair<string,string>> vec;
    for(int i=0;i<n;i++){
        string str1;
        string str2;
        cin>>str1;
        cin>>str2;
        vec.push_back(make_pair(str1,str2));
    }
    for(int i=0;i<n;i++){
        if(check(vec[i].first,vec[i].second)){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}


// // 3
// // KINGSTRING
// // KINGING
// // GIFT
// // GIFT
// // AWESOME
// // AWSOE
// #include <bits/stdc++.h>
// using namespace std;
// bool check(string s1,string s2){
//     unsigned int j=0;
//     unsigned int i=0;
//     string prefix;
//     string postfix;
//     string postfix1;

//     while(i<s1.size()){
//         if(s1[i]==s2[j]){
//             prefix.push_back(s1[i]);
//             j++;
//             i++;
//         }
//         else{
//             while(s1[i]!=s2[j]){
//                 i++;
//             }
//             postfix=s1.substr(i,s1.size()-(i));
//             postfix1=s2.substr(j,s2.size()-(j));
//             cout<<postfix<<endl<<postfix1<<endl<<prefix<<endl;

//             if(prefix+postfix==s2){
//                 if(postfix==postfix1){
//                 return true;
//             }
//             return false;
            
//         }
//     }
//     }
//     return false;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<string> sol(n);
//     vector<pair<string,string>> vec;
//     for(int i=0;i<n;i++){
//         string str1;
//         string str2;
//         cin>>str1;
//         cin>>str2;
//         vec.push_back(make_pair(str1,str2));
//     }
//     for(int i=0;i<n;i++){
//         if(check(vec[i].first,vec[i].second)){
//             cout<<"YES"<<endl;
//         }
//         else
//             cout<<"NO"<<endl;
//     }
    
//     return 0;
// }
