class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> count; // Create a map to store the count of each element

        int n = nums.size();
        for (int num : nums) 
        {
            count[num]++; // Increment the count of each element in the map
            if (count[num] > n / 2) 
            {
                return num; // If the count of an element becomes greater than n/2, it is the majority element
            }
        }

        return -1; // If the majority element doesn't exist, return -1
    }
};
