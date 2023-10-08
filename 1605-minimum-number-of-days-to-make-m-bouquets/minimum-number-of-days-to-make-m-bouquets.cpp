class Solution {
public:
    bool f(vector<int>& nums, int day, int m, int k)
    {
        int cnt=0,ans=0;//ans=number of bouquets

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=day)    cnt++;
            else
            {
                ans += (cnt/k);
                cnt=0;
            }
        }

        ans += (cnt/k);

        return ans>=m;
    }

    int minDays(vector<int>& nums, int m, int k) 
    {
        int n = nums.size();

        if((long long)m*(long long)k > n) return -1;

        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(f(nums,mid,m,k))     high=mid-1;
            else    low=mid+1;
        }

        return low;
    }
};