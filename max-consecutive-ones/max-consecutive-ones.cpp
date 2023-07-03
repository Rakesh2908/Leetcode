class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxi=INT_MIN;
        int i=0;
        int cnt=0;

        while(i<nums.size())
        {
            if(nums[i]==1)
                cnt++;
            else
                cnt=0;
            
            maxi = max(maxi,cnt);
            i++;
        }   
        return maxi;
    }
};