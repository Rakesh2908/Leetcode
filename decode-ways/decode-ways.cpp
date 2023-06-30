class Solution {
public:
    int f(int i, string& s, int n, vector<int>& memo) {
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int ans = 0;
        ans += f(i + 1, s, n, memo);

        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ans += f(i + 2, s, n, memo);

        memo[i] = ans;
        return ans;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        return f(0, s, n, memo);
    }
};
