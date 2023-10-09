class Solution {
public:
    int f(vector<int>& nums, int pages)
    {
        int students=1;
        int curr=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+curr > pages)
            {
                students++;
                curr = nums[i];
            }

            else
            {
                curr += nums[i];
            }
        }

        return students;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        if (k > nums.size()) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high= accumulate(nums.begin(), nums.end(), 0);

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(f(nums,mid) > k)  low=mid+1;
            else    high=mid-1;
        }

        return low;
    }
};