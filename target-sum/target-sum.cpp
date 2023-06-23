class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) 
    {
        int totsum = 0;
        for (auto& x : arr) 
        {
            totsum += x;
        }

        if ((totsum - target) < 0 || (totsum - target) % 2) 
        {
            return 0;
        }

        int tar = (totsum - target) / 2;
        int numWays = 0;
        int N = arr.size();

        vector<vector<int>> dp(N,vector<int>(tar + 1, 0));

        if (arr[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
        }

        if (arr[0] != 0 && arr[0] <= tar) {
            dp[0][arr[0]] = 1;
        }

        for (int ind = 1; ind < N; ind++) {
            for (int sum = 0; sum <= tar; sum++) {
                int notTake = dp[ind - 1][sum];
                int take = 0;
                if (arr[ind] <= sum) {
                    take = dp[ind - 1][sum - arr[ind]];
                }
                dp[ind][sum] = notTake + take;
            }
        }

        return dp[N - 1][tar];
    }
};