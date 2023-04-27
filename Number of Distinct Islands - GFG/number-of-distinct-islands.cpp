//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,
              vector<pair<int,int>>&v,int r0,int c0)
    {
        vis[r][c]=1;
        
        v.push_back({r-r0,c-c0});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    dfs(nrow,ncol,grid,vis,v,r0,c0);
                }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> s;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,vis,v,i,j);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
    
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends