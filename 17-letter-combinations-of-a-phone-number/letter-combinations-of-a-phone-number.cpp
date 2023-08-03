class Solution {
public:
    void f(int i,string digits, unordered_map<char,vector<char>> &hash, vector<string>&ans,string &temp)
    {
        if(i==digits.size())
        {
            ans.push_back(temp);
            return;
        }

        for(char c: hash[digits[i]])
        {
            temp.push_back(c);
            f(i+1,digits,hash,ans,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) 
        {
            return {};
        }

        unordered_map<char,vector<char>> hash;
        hash['2'] = {'a', 'b', 'c'};
        hash['3'] = {'d', 'e', 'f'};
        hash['4'] = {'g', 'h', 'i'};
        hash['5'] = {'j', 'k', 'l'};
        hash['6'] = {'m', 'n', 'o'};
        hash['7'] = {'p', 'q', 'r', 's'};
        hash['8'] = {'t', 'u', 'v'};
        hash['9'] = {'w', 'x', 'y', 'z'};

        vector<string>ans;
        string temp;

        f(0,digits,hash,ans,temp);
        sort(ans.begin(),ans.end());

        return ans;
    }
};