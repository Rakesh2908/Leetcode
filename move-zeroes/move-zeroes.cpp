class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // Pointer to track the position to place the next non-zero element
        int j = 0;  // Pointer to iterate through the array

        while (i < nums.size() && j < nums.size()) 
        {
            if (nums[j] != 0) 
            {
                // If the current element is non-zero, swap it with the element at position i
                swap(nums[i], nums[j]);

                // Move the pointer i to the next position
                i++;
            }

            // Move the pointer j to the next position
            j++;
        }
    }
};
