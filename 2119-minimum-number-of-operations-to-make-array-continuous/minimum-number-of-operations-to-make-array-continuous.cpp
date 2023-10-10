class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size(), i = 0, j = 0;
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums)); 
        for (int M = nums.size(); j < M; ++j) {
            if (nums[i] + n <= nums[j]) ++i;
        }
        return n - j + i;
    }
};