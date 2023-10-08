class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        // Get the sizes of the input vectors
        int n = nums1.size();
        int m = nums2.size();

        // Create a 2D vector 'dp' of size (n+1) x (m+1) initialized with INT_MIN
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
    
        // Iterate through each combination of elements from nums1 and nums2
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= m; ++j) 
            {
                // Calculate the maximum dot product up to this point by considering:
                // 1. Multiplying the current elements and adding it to the maximum dot product from previous elements
                // 2. Comparing with the maximum dot products by excluding either current element from nums1 or nums2
                dp[i][j] = max(nums1[i - 1] * nums2[j - 1] + 
                           max(dp[i - 1][j - 1], 0),
                           max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        
        // The maximum dot product is stored in dp[n][m]
        return dp[n][m];
    }
};
