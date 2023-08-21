class Solution {
public:
    string countAndSay(int n) 
    {
        if (n == 1)
            return "1";

        string prevTerm = countAndSay(n - 1);
        string result = "";

        int count = 1;

        for (int i = 0; i < prevTerm.size(); ++i) 
        {
            if (i+1<prevTerm.size() && prevTerm[i]==prevTerm[i + 1]) 
            {
                count++;
            } 
            
            else 
            {
                result += to_string(count)+prevTerm[i];
                count = 1;
            }
        }

        return result;
    }
};
