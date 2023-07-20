class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();

        // Sort the pairs based on the second element (ascending order)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> dp(n, 1); // Initialize the dp array with 1, as each pair itself forms a valid chain

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If the current pair's start is greater than the end of the previous pair, update dp[i]
                // by considering either to include the current pair or not.
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};