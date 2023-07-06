class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        int sum = 0;

        while (j < n)
        {
            sum += nums[j];

            while (sum >= target)
            {
                mini = min(mini, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }    

        return (mini != INT_MAX) ? mini : 0;
    }
};
