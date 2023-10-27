class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int ans[2] = {0, 0};

        //for all substrings of length 1, it is a palindrome
        for (int i = 0; i < n; i++) 
        {
            dp[i][i] = true;
        }

        //for all substrings of length 2,if(s[i]==s[i+1]),it is palidrome
        for (int i = 0; i < n - 1; i++) 
        {
            if (s[i] == s[i + 1]) 
            {
                dp[i][i + 1] = true;
                ans[0] = i;
                ans[1] = i + 1;
            }
        }

        //for all substrings of length >= 3(i.e diff(j-i) >= 2)
        //if dp[i+1][j-1] is palindrome and if s[i]==s[j], then 
        //dp[i][j] is also palindromic
        for (int diff = 2; diff < n; diff++) 
        {
            for (int i = 0; i < n - diff; i++) 
            {
                int j = i + diff;

                if (s[i] == s[j] && dp[i + 1][j - 1]) 
                {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substr(i, j - i + 1);
    }
};
