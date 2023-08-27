class Solution {
public:
    bool f(int idx,int k,vector<int>&stones,vector<vector<int>>&dp)
    {
        if(idx==stones.size()-1)    return true;
        if(dp[idx][k]!=-1)  return dp[idx][k];

        for(int i=idx+1;i<stones.size();i++)
        {
            int gap = stones[i]-stones[idx];

            if(gap==k-1 || gap==k || gap==k+1)
            {
                if(f(i,gap,stones,dp))
                {
                    return dp[idx][k]=true;
                }
            }
        }

        return dp[idx][k]=false;
    }

    bool canCross(vector<int>& stones) 
    {
        if(stones[1]!=1)    return false;
        int n = stones.size();
        if(n<=1)    return true;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(1,1,stones,dp);
    }
};