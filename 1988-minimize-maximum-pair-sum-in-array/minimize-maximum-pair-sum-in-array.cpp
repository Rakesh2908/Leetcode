class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int result = 0;

        // Pair up the elements as described.
        for (int i = 0; i < n / 2; ++i) 
        {
            result = max(result, nums[i] + nums[n - i - 1]);
        }

        return result;
    }
};