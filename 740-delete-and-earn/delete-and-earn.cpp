class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        unordered_map<int, int> count; // To store the count of each value
        for (int num : nums) {
            count[num]++;
        }

        int maxNum = *max_element(nums.begin(), nums.end()); // Find the maximum value in the input array
        vector<int> dp(maxNum + 1, 0); // Create a DP array to store the maximum points earned up to each value

        dp[1] = count[1]; // Initialize the DP array with the points earned for value 1

        for (int i = 2; i <= maxNum; i++) {
            // For each value i from 2 up to the maximum value in the input array
            // Calculate the maximum points we can earn if we choose the current value i
            // and add it to the points earned from i-2 (skipping the adjacent value to i)
            // Compare it with the points earned from the previous value i-1, and take the maximum
            dp[i] = max(i * count[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[maxNum]; // The final result will be stored in dp[maxNum], which represents the maximum points earned for the entire array
        
    }
};
