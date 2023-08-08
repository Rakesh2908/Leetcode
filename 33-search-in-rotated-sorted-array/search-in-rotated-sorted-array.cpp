class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) 
            {
                return mid;
            }

            if (nums[mid] >= nums[left]) 
            {
                // If nums[mid] is greater or equal to nums[left], 
                // it means the left half of the array is sorted.
                if (target >= nums[left] && target < nums[mid]) 
                {
                    // If target is within the range of the left half,
                    // then we need to search in the left half.
                    right = mid - 1;
                } 
                
                else 
                {
                    // Otherwise, we search in the right half.
                    left = mid + 1;
                }
            } 
            
            else 
            {
                // If nums[mid] is less than nums[left], 
                // it means the right half of the array is sorted.
                if (target > nums[mid] && target <= nums[right]) 
                {
                    // If target is within the range of the right half,
                    // then we need to search in the right half.
                    left = mid + 1;
                } 
                
                else 
                {
                    // Otherwise, we search in the left half.
                    right = mid - 1;
                }
            }
        }
        // If target is not found, return -1.
        return -1;
    }
};
