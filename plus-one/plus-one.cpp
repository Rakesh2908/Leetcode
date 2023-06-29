class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        int carry = 1; // Initialize the carry to 1 since we are incrementing by one
        
        // Traverse the digits from right to left
        for (int i = n - 1; i >= 0; i--) 
        {
            // Add the carry to the current digit
            digits[i] += carry;
            
            // Check if there is a carry for the next digit
            if (digits[i] >= 10) 
            {
                digits[i] %= 10; // Keep only the unit digit
                carry = 1; // Set the carry to 1
            } 
            
            else 
            {
                carry = 0; // Reset the carry to 0 since there is no carry for the next digit
                break; // No need to continue traversal if there is no carry
            }
        }
        
        // If there is still a carry after traversing all digits, insert it at the beginning
        if (carry == 1) 
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;          
    }
};