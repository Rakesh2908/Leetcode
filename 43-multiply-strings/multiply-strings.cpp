class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int m = num1.size(); 
        int n = num2.size();
        vector<int> result(m + n, 0);  // Store intermediate results

        for (int i = m - 1; i >= 0; --i) 
        { 
            for (int j = n - 1; j >= 0; --j) 
            {  
                // Multiply digits
                int product = (num1[i] - '0') * (num2[j] - '0'); 
                // Sum with previous digit 
                int sum = product + result[i + j + 1];  

                // Update least significant digit
                result[i + j + 1] = sum % 10; 
                // Carry over to the most significant digit 
                result[i + j] += sum / 10;  
            }
        }

        string resultStr; 
        for (int digit : result) 
        {  // Convert result to string, skipping leading zeros
            if (!(resultStr.empty() && digit == 0)) 
            {
                resultStr += to_string(digit);
            }
        }

        return resultStr.empty() ? "0" : resultStr;  // Return final product
    }
};
