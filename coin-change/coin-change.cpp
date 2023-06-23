class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) 
        {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            } 
            
            else {
                dp[0][j] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j <= amount; j++) 
            {
                int notTaken = dp[i - 1][j];
                int taken = 1e9;
                
                if (coins[i] <= j) {
                    taken = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(taken, notTaken);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};
