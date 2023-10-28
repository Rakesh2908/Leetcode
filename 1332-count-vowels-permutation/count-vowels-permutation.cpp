class Solution {
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings
    {
        {'s', {'a', 'e', 'i', 'o', 'u'}}, // start
        {'a', {'e'}},
        {'e', {'a', 'i'}},
        {'i', {'a', 'e', 'o', 'u'}},
        {'o', {'i', 'u'}},
        {'u', {'a'}}
    };
    unordered_map<char, vector<int>> dp;

public:
    int countVowelPermutation(int n) 
    {
        dp['s']=dp['a']=dp['e']=dp['i']=dp['o']=dp['u'] = vector<int>(n + 1);
        return solve(n, 's'); // start with s
    }

    int solve(int rem, char prev) 
    {
        // no need to pick further. We have formed 1 string of length = n.
        if (rem == 0) 
            return 1; 
        
        // if the result is already calculated for the current state, directly return it
        if (dp[prev][rem]) 
            return dp[prev][rem]; 

        // try each vowel allowed after the previous character
        for (auto c : mappings.at(prev)) 
            dp[prev][rem] = (dp[prev][rem] + solve(rem - 1, c)) % MOD;
            
        return dp[prev][rem];
    }
};
