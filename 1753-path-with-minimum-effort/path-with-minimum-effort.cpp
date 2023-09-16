class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) 
    {
        int n = height.size();
        int m = height[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;

        priority_queue< pair<int, pair<int, int>> ,
                        vector<pair<int, pair<int, int>>> ,
                        greater<pair<int, pair<int, int>>> >pq;
        pq.push({0,{0,0}});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty())
        {
            int dis=pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            if(r==n-1 && c==m-1)
                return dis;

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int effort = max(dis,abs(height[r][c]-
                                             height[nr][nc]));
                    
                    if(effort < dist[nr][nc])
                    {
                        dist[nr][nc]=effort;
                        pq.push({effort,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};