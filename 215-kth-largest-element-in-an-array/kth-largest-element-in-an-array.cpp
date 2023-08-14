class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        nth_element(nums.begin(), nums.end() - k, nums.end());

        return nums[nums.size()-k];
    }
};