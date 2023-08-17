class Solution {
public:
    int f(int num, vector<int>&dp)
    {
        if(num==0)  return 0;
        if(dp[num]!=-1) return dp[num];

        int mini=INT_MAX;

        for(int i=1;i*i<=num;i++)
        {
            mini = min(mini,1+f(num-i*i,dp));
        }

        return dp[num]=mini;
    }

    int numSquares(int n) 
    {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};