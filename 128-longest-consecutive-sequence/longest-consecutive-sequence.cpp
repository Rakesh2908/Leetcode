class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int count=1;
        int maxcount=1;
        if(nums.size()<=1)
        {
            return nums.size();
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==(nums[i]+1))
            {
                count++;
                maxcount= max(maxcount,count);
            }
            else if(nums[i+1]!=nums[i])
            {
                count=1;
            }
        }
        return maxcount;
    }
};