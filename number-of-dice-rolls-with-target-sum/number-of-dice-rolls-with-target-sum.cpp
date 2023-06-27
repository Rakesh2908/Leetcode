class Solution {
public:
    int mod = 1000000007;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: when n = 0 and target = 0, there is one way to achieve the target sum
        dp[0][0] = 1;

        // Dynamic programming calculation
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= target; j++) 
            {
                for (int dice = 1; dice <= k; dice++) 
                {
                    if (dice <= j) 
                    {
                        // We have two options:
                        // 1. Take the current dice value and calculate the ways for the remaining sum.
                        // 2. Do not take the current dice value and calculate the ways for the same sum.
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - dice]) % mod;
                    }
                }
            }
        }

        return dp[n][target];
    }
};
