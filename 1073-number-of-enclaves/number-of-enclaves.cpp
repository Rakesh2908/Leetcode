class Solution {
public:
    bool isValid(int r,int c,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(r>=0 && r<n && c>=0 && c<m)  return true;
        return false;
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1 && !vis[i][j])
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int r = x + drow[i];
                int c = y + dcol[i];

                if(isValid(r,c,grid) && !vis[r][c] && grid[r][c]==1)
                {
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }            
        }
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};