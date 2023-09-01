class Solution {
public:
    int popCount(int x) 
    {
        int count = 0;
        while (x != 0) 
        {
            // zeroing out the least significant nonzero bit
            x &= x - 1; 
            count++;
        }
        return count;
    }

    vector<int> countBits(int n) 
    {
        vector<int> ans(n + 1);
        for (int x = 0; x <= n; ++x) 
        {
            ans[x] = popCount(x);
        }
        
        return ans;    
    }
};