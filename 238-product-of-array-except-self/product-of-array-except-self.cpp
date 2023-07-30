class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> prefix(n,1);   
        vector<int> postfix(n,1);   
        vector<int> ans(n,1);

        int left=1;
        for(int i=0;i<n;i++)
        {
            prefix[i] = left;
            left *= nums[i];
        }   

        int right=1;
        for(int i=n-1;i>=0;i--)
        {
            postfix[i] = right;
            right *= nums[i];
        }

        for(int i=0;i<n;i++)
        {
            ans[i] = prefix[i]*postfix[i];
        }

        return ans;
    }
};