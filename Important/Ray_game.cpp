#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<string>> mat){
    for(int i=0;i<mat.size();i++,cout<<endl){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
    }
}

pair<int,int> findRayPosition(string ray){
    if(ray[0]=='R'){
        int row=ray[1]-'0';
        return(make_pair(4-row,0));
    }
    else{
        int col=ray[1]-'0';
        return(make_pair(4,col));
    }
}

string findRay(int i,int j){
    string temp;
    if(j==0){
        temp.push_back('R');
        temp.push_back('0'+(4-i));
    }
    else{
        temp.push_back('C');
        temp.push_back('0'+j);
    }
    return temp;
}

void removeRay(vector<string> &rays,string ray){
    for(int i=0;i<rays.size();i++){
        if(rays[i]==ray){
            rays[i]="";
        }
    }
}

void projectRay(vector<vector<string>> &mat, string ray,vector<string> &rays,string axis,int st_row,int st_col){
    int row=st_row;
    int col=st_col;
    if(ray[0]=='R'){
        col=st_col+1;
        while(col<4){
            if(mat[row-1][col]=="X"){
                mat[4][col]=ray;
                removeRay(rays,findRay(4,col));
                break;
            }
            else if(mat[row+1][col]=="X"){
                mat[0][col]=ray;
                break;
            }            
            else if(mat[row][col+1]=="X"){
                mat[st_row][st_col]="H";
                break;
            }
            else if(mat[row-1][col+1]=="X" && mat[row+1][col+1]=="X"){
                mat[st_row][st_col]="R";
                break;
            }
            else if(mat[row-1][col+1]=="X"){
                mat[4][col]=ray;
                removeRay(rays,findRay(4,col));
                break;
            }
            else if(mat[row+1][col+1]=="X"){
                mat[0][col]=ray;
                break;
            }
            else{
                if(col==3){
                    mat[row][col+1]=ray;
                    break;
                }
            }
            col++;
        }
    }
    else{
        row=row-1;
        while(row>0){
            if(mat[row-1][col]=="X"){
                mat[st_row][st_col]="H";
            }
            else if(mat[row-1][col-1]=="X" && mat[row-1][col+1]=="X"){
                mat[st_row][st_col]="R";
            }
            else if(mat[row-1][col+1]=="X"){
                mat[row][0]=ray;
                removeRay(rays,findRay(row,0));
            }
            else if(mat[row-1][col-1]=="X"){
                mat[row][4]=ray;
            }
            row--;
        }
    }

}

void projectRayUtil(vector<vector<string>> &mat, vector<string> &rays){
    cout<<"Util here"<<endl;
    for(int i=0;i<rays.size();i++){
        if(rays[i]!=""){
        int st_row = findRayPosition(rays[i]).first;
        int st_col = findRayPosition(rays[i]).second;
        mat[st_row][st_col]=rays[i];
        string axis = st_col==0 ? "R":"C";
        projectRay(mat,rays[i],rays,axis,st_row,st_col);
        }
    }
}

int main(){
    vector<vector<string>> mat(5,(vector<string>(5,"   ")));
    for(int i=1;i<mat.size()-1;i++){
        for(int j=1;j<mat.size()-1;j++){
            mat[i][j]=" - ";
        }
    }
    int times=0;
    cin>>times;
    while(times--){
        int i,j;
        cin>>i>>j;
        mat[i+1][j+1]="X";
    }
    cin>>times;
    vector<string> rays;
    while(times--){
        string ray;
        cin>>ray;
        rays.push_back(ray);
    }
    projectRayUtil(mat,rays);
    display(mat);
    for(auto ray:rays){
        cout<<ray<<endl;
    }
    return 0;
}