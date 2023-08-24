class Solution {
public:
    typedef long long ll;
    int minAbsoluteDifference(vector<int>& nums, int x) 
    {
        if(x==0) 
            return 0; // If x is 0, any pair will have a difference of at least 0.
        int n = nums.size();
        
        int ans = 1e9; // Initialize ans to a large value.
        
        set<int> s; // Create a set to store elements.
        
        for(int i=x; i<n; i++) 
        {
            s.insert(nums[i-x]); 
            
            auto ind = s.lower_bound(nums[i]); // Find the lower bound of current element.
            
            if(ind!=s.end())  // Check with next greater element.
            {
                ans = min(ans,abs(*ind - nums[i]));
            }

            if(ind!=s.begin())  // Check with previous element.
            {
                ind--;
                ans = min(ans,abs(*ind - nums[i]));
            }
        }
        
        return ans; // Return the minimum absolute difference.
    }
};
