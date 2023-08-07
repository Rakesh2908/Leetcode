class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) 
    {
        bool flag=false;
        
        if (nums.size() < 3) 
        {
            return true;
        }
        
        for (int i = 0; i < nums.size()-1; i++) 
        {
            if ( m < 1 + nums[i + 1] + nums[i]) 
            {
                flag=true;
            }
        }
        
        return flag; 
    }
};
