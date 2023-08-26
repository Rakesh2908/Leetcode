class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int l=0,r;
        int maxi=0;

        for(r=0;r<nums.size();r++)
        {
            if(nums[r]==0)
            {
                k--;
            }

            if(k<0)
            {
                k+=1-nums[l];
                l++;
            }
        }

        return r-l;
    }
};