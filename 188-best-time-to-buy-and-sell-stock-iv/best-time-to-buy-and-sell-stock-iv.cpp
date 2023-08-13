class Solution {
public:
    int memoizedDP(int ind, int buy, int cap, std::vector<int>& prices,
                   std::unordered_map<std::string, int>& memo) 
    {
        if (ind == prices.size() || cap == 0) 
        {
            return 0;
        }

        string key = to_string(ind) + "_" + to_string(buy) + "_" + 
                    to_string(cap);

        if (memo.find(key) != memo.end()) 
        {
            return memo[key];
        }

        int profit = 0;

        if (buy == 0) 
        {
            profit = max(0 + memoizedDP(ind + 1, 0, cap, prices, memo),
                -prices[ind] + memoizedDP(ind + 1, 1, cap, prices, memo));
        } 
        
        else if (buy == 1) 
        {
            profit = max(0 + memoizedDP(ind + 1, 1, cap, prices, memo),
                prices[ind] + memoizedDP(ind + 1, 0, cap - 1, prices, memo));
        }

        memo[key] = profit;
        return profit;
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        unordered_map<string, int> memo;

        return memoizedDP(0, 0, k, prices, memo);    
    }
};