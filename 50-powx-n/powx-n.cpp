class Solution {
public:
    double myPow(double x, int n) 
    {
        if (n == 0) 
        {
            return 1.0;   // Base case: x^0 = 1
        }
        
        // Recursive call to compute x^(n/2)
        double half = myPow(x, n / 2);   
        
        // Check if n is even or odd
        if (n % 2 == 0) 
        {
            return half * half;   // If n is even, x^n = (x^(n/2))^2
        } 
        
        else if (n > 0) 
        {
            // If n is odd and positive, x^n = x * (x^(n/2))^2
            return x * half * half;   
        } 
        
        else 
        {
            // If n is odd and negative, x^n = (1/x) * (x^(n/2))^2
            return (1 / x) * half * half;   
        }
    }
};
