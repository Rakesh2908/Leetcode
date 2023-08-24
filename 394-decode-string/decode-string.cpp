class Solution {
public:

    string decodeString(string s) 
    {
        int i = 0;
        return decode(s, i);
    }

    string decode(string& s, int& i) 
    {
        string result = "";

        while (i < s.length() && s[i] != ']') 
        {
            if (isdigit(s[i])) 
            {
                int count = 0;

                while (isdigit(s[i])) 
                {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }

                i++;  // skip '['
                string decodedStr = decode(s, i);
                i++;  // skip ']'

                while (count > 0) 
                {
                    result += decodedStr;
                    count--;
                }
            } 
            
            else 
            {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};
