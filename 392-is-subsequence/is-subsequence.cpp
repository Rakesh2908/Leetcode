class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        // If the subsequence string is empty, it is always present in any string.
        if (n == 0) return true;
        
        int dp[n + 1][m + 1];

        // Base case: if either of the strings is empty, no subsequence can be formed.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // If the characters match, we include this character in the subsequence.
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If the characters don't match, skip one character in 's' and try again
                    // or skip one character in 't' and try again, take the maximum of these two possibilities.
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // If the length of the longest common subsequence between 's' and 't' is equal to the length of 's',
        // then 's' is a subsequence of 't'.
        return (dp[n][m] == n);
    }
};
