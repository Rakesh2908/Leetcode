class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        int n = nums.size();
        multiset<int>s;
        int cnt=0;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                s.insert(nums[i]+nums[j]);
            }
        }

        for(auto it: s)
        {
            if(it<target)   cnt++;
        }

        return cnt;
    }
};