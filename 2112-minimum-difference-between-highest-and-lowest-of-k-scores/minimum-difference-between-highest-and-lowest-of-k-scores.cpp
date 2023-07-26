class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        if(k==1)    return 0;

        sort(nums.begin(),nums.end());

        int l=0;
        int r=k-1;

        int ans=INT_MAX;

        while(r < nums.size())
        {
            int diff = nums[r]-nums[l];

            ans = min(ans,diff);

            l++;
            r++;
        }
        return ans;
    }
};