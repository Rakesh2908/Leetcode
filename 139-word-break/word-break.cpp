class Solution {
public:
    bool f(int ind,string s,vector<int>&dp,unordered_set<string>st)
    {
        if(ind==s.size())   return true;
        
        if(dp[ind]!=-1) return dp[ind];

        for(int i=ind;i<s.size();i++)
        {
            string sub = s.substr(ind,i-ind+1);

            if(st.find(sub) != st.end())
            {
                if(f(i+1,s,dp,st)==true)
                {
                    return true;
                }
            }
        }

        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& words) 
    {
        unordered_set<string>st(words.begin(),words.end());
        int n = s.size();
        vector<int>dp(n+1,-1);
        return f(0,s,dp,st);
    }
};