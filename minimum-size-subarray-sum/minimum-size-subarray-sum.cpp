class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int i=0;
        int j=0;
        int mini=INT_MAX;
        int sum=0;

        while(i<n && j<n)
        {
            sum += nums[j];

            while(sum>=target)
            {
                mini = min(mini,j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }
        if(mini==INT_MAX)   return 0;
        return mini;
    }
};