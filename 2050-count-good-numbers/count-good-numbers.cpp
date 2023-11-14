class Solution {
public:
    long long mod = 1000000007;

    long long f(long long a, long long b) {
        if (b == 0) return 1;
        if (b < 0) return 1 / f(a, -1 * b);

        if (b % 2 == 1)
            return ((a % mod) * (f((a * a) % mod, (b - 1) / 2) % mod)) % mod;
        else
            return f((a * a) % mod, b / 2) % mod;
    }

    int countGoodNumbers(long long n) {
        long long ans = 1;
        if (n % 2 == 1)
            ans = (f(5 * 1LL, n / 2 + 1) * f(4 * 1LL, n / 2)) % mod;
        else
            ans = (f(5 * 1LL, n / 2) * f(4 * 1LL, n / 2)) % mod;
        return static_cast<int>(ans);
    }
};
