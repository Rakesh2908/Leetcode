class Solution {
public:
    int change(int sum, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return f(n-1,coins,sum,dp);
    }

    int f(int ind, vector<int>& coins, int sum, vector<vector<int>> &dp)
    {
        if(ind == 0)    return (sum%coins[0] == 0);
        
        if(dp[ind][sum] != -1)  return dp[ind][sum];
        
        int notTake = f(ind-1,coins,sum,dp);
        int take = 0;
        
        if(coins[ind] <= sum)   
            take = f(ind,coins,sum-coins[ind],dp);
        
        return dp[ind][sum] = take + notTake;
    }
};