#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool parseBoolExpr(string str)
    {
        int ind = 0;
        return solve(str, ind);
    }
    bool solve(string &str, int &ind)
    {
        char ch = str[ind];
        if (ch == '!')
            return Not(str, ind);
        else if (ch == '&')
            return And(str, ind);
        else if (ch == '|')
            return Or(str, ind);
        else
            return Base(str, ind);
    }
    bool And(string &str, int &ind)
    {
        ind += 2;
        bool res = true;
        while (str[ind] != ')')
            if (str[ind] == ',')
                ind++;
            else
                res &= solve(str, ind);
        ind++;
        return res;
    }
    bool Or(string &str, int &ind)
    {
        ind += 2;
        bool res = false;
        while (str[ind] != ')')
            if (str[ind] == ',')
                ind++;
            else
                res |= solve(str, ind);
        ind++;
        return res;
    }
    bool Not(string &str, int &ind)
    {
        ind += 2;
        bool res = solve(str, ind);
        ind++;
        return !res;
    }
    bool Base(string &str, int &ind)
    {
        char ch = str[ind];
        ind++;
        return (ch == 't') ? true : false;
    }
};