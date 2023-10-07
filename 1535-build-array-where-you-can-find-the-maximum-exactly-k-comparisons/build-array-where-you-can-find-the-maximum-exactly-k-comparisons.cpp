class Solution 
{
public:
    vector<vector<vector<int>>> dp;
    int MOD = 1e9 + 7;
    int n;
    int m;
    
    int numOfArrays(int n, int m, int k) 
    {
        dp = vector(n, vector(m + 1, vector(k + 1, -1)));
        this->n = n;
        this->m = m;
        return f(0, 0, k);
    }
    
    int f(int i, int maxSoFar, int remain) {
        if (i == n) 
        {
            if (remain == 0) 
            {
                return 1;
            }
            
            return 0;
        }
        
        if (remain < 0) 
        {
            return 0;
        }
        
        if (dp[i][maxSoFar][remain] != -1) 
        {
            return dp[i][maxSoFar][remain];
        }
        
        int ans = 0;

        for (int num = 1; num <= maxSoFar; num++) 
        {
            ans = (ans + f(i + 1, maxSoFar, remain)) % MOD;
        }

        for (int num = maxSoFar + 1; num <= m; num++) 
        {
            ans = (ans + f(i + 1, num, remain - 1)) % MOD;
        }
                
        return dp[i][maxSoFar][remain] = ans;
    }
};