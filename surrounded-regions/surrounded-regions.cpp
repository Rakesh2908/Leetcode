class Solution {

private:
    void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &mat, int delrow[], int delcol[]) 
    {
        vis[row][col] = 1; 

        int n = mat.size();
        int m = mat[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) 
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
                && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') 
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        
        vector<vector<int>> vis(n, vector<int>(m,0)); 
        
        // traverse first row and last row 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(!vis[i][j] && mat[i][j]=='O')
                    {
                        dfs(i, j, vis, mat, delrow, delcol);
                    }
                }
            }
        }
        
        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) 
        {
            for(int j= 0 ;j<m;j++) 
            {
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }

    }
};

