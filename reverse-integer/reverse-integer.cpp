class Solution {
public:
    int reverse(int x) 
    {
        long y = 0;
        while (x != 0) 
        {
            y = 10 * y + x % 10;
            x = x / 10;
        }
        
        if (!(y >= INT_MIN && y <= INT_MAX)) return 0;
        
        return static_cast<int>(y);
    }
};
