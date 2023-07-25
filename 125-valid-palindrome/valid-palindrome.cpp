class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str;
        string t = "";

        for (int i = 0; i < s.size(); i++) 
        {
            if (isalnum(s[i])) // Check if the character is alphanumeric
                str.push_back(tolower(s[i])); // Convert the character to lowercase and add to str
        }

        string temp = str;
        reverse(temp.begin(), temp.end()); // Reverse the string

        return (str == temp); // Check if str is equal to its reverse
    }
};
