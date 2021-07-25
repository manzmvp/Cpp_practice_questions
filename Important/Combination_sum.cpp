#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void sumlist(vector<int> arr,int sum, int i,vector<vector<int>> &res, vector<int> &r){
    if(sum==0){
        res.push_back(r);
        return;
    }
    while(i<arr.size() && sum-arr[i]>=0){
        r.push_back(arr[i]);
        sumlist(arr,(sum-arr[i]),i,res,r);
        i++;
        r.pop_back();
    }
    
}

vector<vector<int>> sumUtil(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    vector<vector<int>> res;
    vector<int> r;
    int i=0;
    sumlist(arr, sum, i, res, r);
    return res;
}

int main(){
    vector<int> arr={2, 4, 6, 8};
    int sum=8;
    vector<vector<int>> ans=sumUtil(arr, sum);
    for(int i=0;i<ans.size();i++,cout<<endl){
        if(ans[i].size()>0){
            cout<<"( ";
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<")";
        }
    }

    return 0;
}