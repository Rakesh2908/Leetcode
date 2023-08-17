class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int i = 0, j = 0;
        int maxi = 0;

        while (i < n && j < n) 
        {
            if (st.count(s[j]) > 0)
            {
                st.erase(s[i]);
                i++;
            }
            else
            {
                st.insert(s[j]);
                maxi = max(maxi, j - i + 1);
                j++;
            }
        }

        return maxi;
    }
};
