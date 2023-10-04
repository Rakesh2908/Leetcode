class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int front=1;
        int back=1;
        int maxi=INT_MIN;  
        
        for(int i=0;i<nums.size();i++)
        {
            if(front==0)    front=1;
            if(back==0)     back=1;

            front *= nums[i];
            back *= nums[nums.size()-i-1];

            maxi = max({maxi,front,back});
        }

        return maxi;
    }
};