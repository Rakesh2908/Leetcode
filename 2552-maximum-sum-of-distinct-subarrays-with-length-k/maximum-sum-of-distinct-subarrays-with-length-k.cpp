class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int left = 0, right = 0;
        long long maxSum = 0, currentSum = 0;
        unordered_set<int> distinctElements;

        while (right < n) 
        {
            while (distinctElements.count(nums[right]) > 0 || 
                    right - left + 1 > k) 
            {
                distinctElements.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }

            distinctElements.insert(nums[right]);
            currentSum += nums[right];
            right++;

            if (right - left == k) 
            {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};