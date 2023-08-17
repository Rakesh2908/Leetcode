class Solution {
public:
    bool isValid(int r,int c,vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (r>=0 && r<n && c>=0 && c<m) return true;

        return false;
    }

    void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<int>> &grid, int delrow[], int delcol[])
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col]=1;

        for(int i=0;i<4;i++)
        {
            int r = row + delrow[i];
            int c = col + delcol[i];

            if(isValid(r,c,grid) && !vis[r][c] && !grid[r][c])
            {
                dfs(r,c,vis,grid,delrow,delcol);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(!vis[i][j] &&  !grid[i][j])
                    {
                        dfs(i, j, vis, grid, delrow, delcol);
                    }
                }
            }
        }

        int cnt=0;

        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(!vis[i][j] && !grid[i][j])
                {
                    dfs(i, j, vis, grid, delrow, delcol);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};