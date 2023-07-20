class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for (auto num : nums) 
        {
            mp[num]++;
        }

        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int earn1 = 0, earn2 = 0;

        for (int i = 0; i < nums.size(); i++) 
        {
            int curr = nums[i] * mp[nums[i]];

            if (i > 0 && nums[i] == nums[i - 1] + 1) 
            {
                int temp = earn2;
                earn2 = max(curr + earn1, earn2);
                earn1 = temp;
            } 
            
            else 
            {
                int temp = earn2;
                earn2 = curr + earn2;
                earn1 = temp;
            }
        }

        return earn2;
        
    }
};
