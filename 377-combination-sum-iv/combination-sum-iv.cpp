class Solution {
private:
    int helper(int target, vector<int>& nums, vector<int>& memo) {
        if (target == 0) {
            return 1;
        }

        if (memo[target] != -1) {
            return memo[target];
        }

        int combinations = 0;
        for (int num : nums) {
            if (target >= num) {
                combinations += helper(target - num, nums, memo);
            }
        }

        memo[target] = combinations;
        return combinations;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        memo[0] = 1;
        return helper(target, nums, memo);
    }
};
