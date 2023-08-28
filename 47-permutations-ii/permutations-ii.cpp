class Solution {
public:
    vector<vector<int>> ans;

    void f(int idx,vector<int>&nums)
    {
        if(idx==nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int>used;

        for (int i = idx; i < nums.size(); ++i)
        {
            if(used.find(nums[i]) != used.end()) continue;

            swap(nums[idx],nums[i]);
            f(idx+1,nums);
            swap(nums[idx],nums[i]);

            used.insert(nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        f(0,nums);
        return ans;
    }
};