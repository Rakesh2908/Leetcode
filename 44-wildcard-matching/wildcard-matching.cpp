class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n=s.length();
        int m=p.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,s,p,dp);   
    }

    bool solve(int ind1,int ind2,string &s,string &p,vector<vector<int>> &dp)
    {
        //if both strings are exhausted return true
        if(ind1<0 && ind2<0) return true;
        // if string p gets exhausted there's ntng to compare so return false
        if(ind2<0 && ind1>=0) return false;

        // if string s gets exhausted, as * can take no value or any value, if only
        // we have all * in string p, we can count them as empty
        if(ind1<0 && ind2>=0)
        {
            for(int i=0;i<=ind2;i++)
            {
                if(p[i]!='*') 
                    return false;
            }
            return true;
        }

        if(dp[ind1][ind2]!=-1) 
            return dp[ind1][ind2];

        //as ? denotes single character it can replace so we go to the next case
        if(s[ind1]==p[ind2] || p[ind2]=='?') 
            return dp[ind1][ind2]=solve(ind1-1,ind2-1,s,p,dp);
        
    //Call f(i-1,j). i.e replace ‘*’ with nothing and act as if it was not present.
//Call f(i,j-1). i.e replace ‘*’ with a single character at index j and make the i pointer to still point at index i
        else if(p[ind2]=='*')
        {
            return dp[ind1][ind2] = solve(ind1-1,ind2,s,p,dp) || 
                                    solve(ind1,ind2-1,s,p,dp);
        }
        return dp[ind1][ind2]=false;
    }
};