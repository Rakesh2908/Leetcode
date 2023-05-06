class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1, res = 0, mod = 1e9 + 7;

        // precalculate 2^i mod mod for i from 0 to n-1
        vector<int> pows(n, 1); 

        for (int i = 1; i < n; ++i) 
        {
            pows[i] = pows[i-1] * 2 % mod;
        }

        while (i <= j) 
        {
            if (nums[i] + nums[j] > target) 
            {
                --j;
            } 
            
            else 
            {
                res = (res + pows[j-i]) % mod; // add 2^(j-i) to res
                ++i;
            }
        }
        return res;
    }
};
