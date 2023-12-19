class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>>ans(m,vector<int>(n));

        int dr[9]={-1,-1,-1,0,0,1,1,1,0};
        int dc[9]={-1,0,1,-1,1,-1,0,1,0};

        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                int sum=0;
                int cnt=0;

                for(int i=0;i<9;i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr>=0 && nr<m && nc>=0 && nc<n)
                    {
                        sum += img[nr][nc];
                        cnt += 1;
                    }
                }

                ans[r][c] = sum/cnt;
            }
        }    

        return ans;
    }
};