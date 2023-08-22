class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans="";
        
        while(n)
        {
            n--;
            int rem=n%26;
            ans += (char)(rem+'A');
            n /= 26;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};