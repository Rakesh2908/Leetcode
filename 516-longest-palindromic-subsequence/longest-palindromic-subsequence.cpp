class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>>&dp)
    {
        if (i < 0 || j < 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        // Compare characters for equality
        if (s[i] == t[j])
            // If equal, add 1 to the result and move diagonally
            return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
        else
            // If not equal, take the maximum of results from the previous positions
            return dp[i][j] = max(f(i, j - 1, s, t, dp), f(i - 1, j, s, t, dp));
    }

    int longestPalindromeSubseq(string s) 
    {
        string t = string(s.rbegin(), s.rend());
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(n - 1, n - 1, s, t, dp);
    }
};
