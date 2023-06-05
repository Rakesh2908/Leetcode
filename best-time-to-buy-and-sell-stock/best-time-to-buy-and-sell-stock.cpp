class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini=INT_MAX; //minimum price
        int maxi=0; //maximum profit

        for(auto it: prices)
        {
            if(it < mini)
                mini = it;
            
            if(maxi < it - mini)
                maxi = it - mini;
        }
        return maxi;
    }
};