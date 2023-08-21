class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> prevMap;  // value -> index

        for (int i = 0; i < nums.size(); i++) 
        {
            int diff = target - nums[i];
            
            if (prevMap.find(diff) != prevMap.end()) 
            {
                return {prevMap[diff], i};
            }

            prevMap[nums[i]] = i;
        }

        // If no solution is found, return an empty vector.
        return {};
    }
};