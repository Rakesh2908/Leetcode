class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) 
        {
            return false;
        }

        unordered_map<char, int> countS, countT;

        for (int i = 0; i < s.length(); i++) 
        {
            countS[s[i]] += 1;
            countT[t[i]] += 1;
        }

        return countS == countT;
    }
};