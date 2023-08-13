class Solution {
public:
    bool f(int idx,vector<int>&dp,vector<int>&nums)
    {
        if(idx<0)   return true;
        if(dp[idx]!=-1) return dp[idx];

        bool equal2=false;
        bool equal3=false;
        bool inc=false;

        if(idx>0 && nums[idx]==nums[idx-1])
            equal2 = f(idx-2,dp,nums);
        
        if(idx>1 && nums[idx]==nums[idx-1] && nums[idx]==nums[idx-2])   
            equal3 = f(idx-3,dp,nums);
        
        if(idx>1 && nums[idx]==nums[idx-1]+1 && nums[idx]==nums[idx-2]+2)   
            inc = f(idx-3,dp,nums);

        return dp[idx]=equal2||equal3||inc;
    }

    bool validPartition(vector<int>& nums) 
    {
        vector<int>dp(nums.size(),-1);
        return f(nums.size()-1,dp,nums);
    }
};