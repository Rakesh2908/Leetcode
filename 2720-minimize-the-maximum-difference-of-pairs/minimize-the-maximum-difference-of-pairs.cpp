class Solution {
public:
    bool isPossible(vector<int>&nums,int p, int diff)
    {
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1] <= diff)
            {
                p--;
                i++;//an element cant be taken twice
            }
        }

        return (p<=0);
    }

    int minimizeMax(vector<int>& nums, int p) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        //min and max difference possible in sorted array
        int left=0;
        int right=nums[n-1]-nums[0];
        int ans=right;//it contains max difference

        while(left <= right)
        {
            int mid = left + (right-left)/2;

            if(isPossible(nums,p,mid))
            {
                ans=mid;
                right=mid-1;
            }

            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};