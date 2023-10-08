class Solution {
public:
    long long f(vector<int>&nums, int num)
    {
        long long sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum += ceil((double)nums[i]/(double)num);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int mini=INT_MAX;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(f(nums,mid) <= (long long)threshold)    high=mid-1;
            else    low=mid+1;
        }

        return low;
    }
};