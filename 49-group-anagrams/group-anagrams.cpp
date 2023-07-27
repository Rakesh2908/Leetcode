class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>> mp; // sorted, all words 

        for(auto s: strs)
        {
            string word = s;
            sort(word.begin(),word.end());
            mp[word].push_back(s);
        }

        vector<vector<string>> ans;
        
        for(auto s: mp)
        {
            ans.push_back(s.second);
        }

        return ans;
    }
};