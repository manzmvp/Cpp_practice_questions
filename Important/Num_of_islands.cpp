// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of islands.
    bool isSafe(vector<vector<char>>& visited,int row,int col,vector<vector<char>>& grid,int m,int n )
    {
        if((row>=0) && (row<m) && (col>=0) && (col<n) && (grid[row][col]=='1') && (visited[row][col]=='0'))
        {
            return true;
        }
        return false;
    }
    void DFS(vector<vector<char>>& visited,int row,int col,vector<vector<char>>& grid,int m,int n)
    {
      visited[row][col]='1';    
      int rowtable[8]={-1,-1,-1,0,0,1,1,1};
      int coltable[8]={-1,0,1,-1,1,-1,0,1};
      
      for(int k=0;k<8;k++)
      {
          if(isSafe(visited,row+rowtable[k],col+coltable[k],grid,m,n))
          {
              DFS(visited,row+rowtable[k],col+coltable[k],grid,m,n);
          }
      }
      
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<char>>visited(m, vector<char>(n, '0'));
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //      visited[i][j]=0;    
        //     }
        // }
        int count=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[i].size();j++)
           {
               if(grid[i][j]=='1' && visited[i][j]=='0')
               {
                   DFS(visited,i,j,grid,m,n);
                   count++;
               }
           }
           
       }
       return count;
    }
};

// { Driver Code Starts.
int main(){
        int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	return 0;
}  // } Driver Code Ends
// 4 2
// 0 1
// 1 0
// 1 1
// 1 0