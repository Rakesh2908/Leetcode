class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==3)    return nums[0]+nums[1]+nums[2];

        int mini=nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-2;i++)
        {
            int left=i+1;
            int right=n-1;

            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];

                if(abs(sum-target) < abs(mini-target))
                {
                    mini=sum;
                }

                if(sum<target)
                {
                    left++;
                }

                else
                {
                    right--;
                }
            }
        }

        return mini;
    }
};