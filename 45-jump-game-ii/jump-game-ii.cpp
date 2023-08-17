class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx <= 0) return 0; 

        if (dp[idx] != -1) return dp[idx]; 

        int minJumps = INT_MAX;

        for (int i = 0; i < idx; i++) 
        {
            if (i + nums[i] >= idx) 
            {
                int jumps = f(i, nums, dp);
                minJumps = min(minJumps, jumps + 1);
            }
        }

        return dp[idx] = minJumps;
    }

    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return f(n - 1, nums, dp);
    }
};
