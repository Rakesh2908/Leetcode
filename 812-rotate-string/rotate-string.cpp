class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.length()!=goal.length())
            return false;    

        for(int i=0;i<s.length();i++)
        {
            string temp=goal;

            reverse(temp.begin(), temp.begin() + goal.length() - i);
                
            reverse(temp.begin() + goal.length() - i, temp.end());

            reverse(temp.begin(), temp.end());

            if(temp == s)
                return true;
        }

        return false;
    }
};