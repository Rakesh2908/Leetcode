class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int fresh=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }

                else
                {
                    vis[i][j]=0;
                    if(grid[i][j]==1)   fresh++;
                }
            }
        }

        int tm=0;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int freshToRotten=0;

        while(!q.empty())
        {
            auto p = q.front();
            int x = p.first.first;
            int y = p.first.second;
            int t = p.second;

            tm = max(t,tm);

            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr = x + drow[i];
                int nc = y + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0
                    && grid[nr][nc]==1)
                {
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=1;
                    freshToRotten++;
                }
            }
        }

        if(fresh != freshToRotten)  return -1;

        return tm;
    }
};