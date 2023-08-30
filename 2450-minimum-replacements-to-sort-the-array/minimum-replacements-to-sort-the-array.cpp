int fastio = [] {std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long int i = 0, n = nums.size();
        
        long long int  prev = nums[n-1];       
        
        long long int res = 0;
        for( i = n-2; i>=0 ;i--)
        {
            long long int times = (nums[i] / prev );

            if( (nums[i] %prev) != 0 ) 
            { 
                times += 1;
                
                prev  =  nums[i] / times;
            }      
            res +=  times - 1;
                
            
        }
            
        return res;
    }
};