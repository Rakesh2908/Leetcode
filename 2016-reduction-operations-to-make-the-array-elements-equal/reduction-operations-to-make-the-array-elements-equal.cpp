class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        int cnt=0,ans=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])   cnt++;
            ans += cnt;
        }

        return ans;
    }
};