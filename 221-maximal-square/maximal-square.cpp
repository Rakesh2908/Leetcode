class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int maxi=0;

        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i==0 || j==0)
                    {
                        dp[i][j]=1;
                    }

                    else
                    {
                        dp[i][j]=1+/*top,left,top-left*/
                        min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    }

                    maxi=max(maxi,dp[i][j]);
                }
            }
        } 

        return maxi*maxi;   
    }
};