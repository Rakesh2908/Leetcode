class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if (divisor == 0) {
            return INT_MAX;
        }
        
        if (dividend == 0) {
            return 0;
        }
        
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long ldividend = std::abs(static_cast<long long>(dividend));
        long long ldivisor = std::abs(static_cast<long long>(divisor));
        
        long long quotient = 0;
        while (ldividend >= ldivisor) {
            long long tempDivisor = ldivisor, count = 1;
            
            while (ldividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                count <<= 1;
            }
            
            ldividend -= tempDivisor;
            quotient += count;
        }
        
        return static_cast<int>(std::min(std::max(sign * quotient, static_cast<long long>(INT_MIN)), static_cast<long long>(INT_MAX)));
    }
};