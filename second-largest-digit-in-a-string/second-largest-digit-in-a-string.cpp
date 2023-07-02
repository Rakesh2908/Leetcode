class Solution {
public:
    int secondHighest(string s) {
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] >= '0' && s[i] <= '9') 
            {
                int digit = s[i] - '0';  
                ans.push_back(digit);
            }
        }

        sort(ans.begin(), ans.end());
        //Removing duplicates
        ans.erase(unique(ans.begin(),ans.end()), ans.end());

        if (ans.empty() || ans.size() == 1) 
        {
            // If there are no digits or only one digit in the string
            return -1;  
        }
        return ans[ans.size() - 2]; 
    }
};
