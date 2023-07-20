class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> hash;

        hash['I']=1;
        hash['V']=5;
        hash['X']=10;
        hash['L']=50;
        hash['C']=100;
        hash['D']=500;
        hash['M']=1000;

        int ans = 0;
        int i = s.size() - 1;

        while (i >= 0) 
        {
            if (i > 0 && hash[s[i]] > hash[s[i - 1]]) 
            {
                // Move two steps back as we considered two characters
                ans += hash[s[i]] - hash[s[i - 1]];
                i -= 2; 
            } 

            else 
            {
                ans += hash[s[i]];
                i--; // Move one step back
            }
        }

        return ans;
    }
};