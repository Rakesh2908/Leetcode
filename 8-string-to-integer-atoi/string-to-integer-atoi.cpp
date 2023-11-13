class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();

        while(s[i]==' ')
            i++;
        
        int pos=0,neg=0;

        if(s[i]=='-')
        {
            neg++;
            i++;
        }

        if(s[i]=='+')
        {
            pos++;
            i++;
        }

        double ans=0;

        while(i<n && s[i]>='0' && s[i]<='9')
        {
            ans = (ans*10)+(s[i]-'0');
            i++;
        }

        if(neg > 0) ans = -ans;
        if(pos>0 && neg>0)  return 0;

        if(ans < INT_MIN)   return INT_MIN;
        if(ans > INT_MAX)   return INT_MAX;

        return (int)ans;
    }
};