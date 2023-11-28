class Solution {
public:
    int numberOfWays(string corridor) 
    {
        int a = 1, b = 0, b2 = 0, c = 0, mod = 1e9 + 7;
        for (char& ch: corridor)
            if (ch == 'S')
                a = (a + c) % mod, c = b, b = a, a = 0;
            else
                a = (a + c) % mod;
        return c;
    }
};