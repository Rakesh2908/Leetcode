class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        map<int,int> counts;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
            counts[nums[i]]++;

        for(auto it :counts)
            if(it.second > nums.size()/3) 
                ans.push_back(it.first);

        return ans;
    }
};