class Solution {
public:
    int solve(int n , vector<int>&dp)
    {
        if(n<=3)    return n;
        if(dp[n]!= -1)  return dp[n];

        int maxi = INT_MIN;

        for(int i=2;i<n;i++)
        {
            maxi = max(maxi, i* solve(n-i, dp));
        }

        return dp[n] = maxi;
    }

    int integerBreak(int n) 
    {
        if(n<=3)    return n-1;
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};