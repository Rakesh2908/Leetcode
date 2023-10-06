class Solution {
public:
    int f(int n, vector<int>&dp)
    {
        if(n<=3)    return n-1;

        if(dp[n]!=0)    return dp[n];

        int ans = n;

        for(int i=2;i<n;i++)
        {
            ans = max(ans, i * max(n - i, f(n - i, dp)));
        }

        return dp[n]=ans;
    }

    int integerBreak(int n)
    {
        if(n<=3)    return n-1;
        vector<int>dp(n+1,0);

        return f(n,dp);
    }
};