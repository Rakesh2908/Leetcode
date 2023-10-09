class Solution {
public:
    int f(vector<int>& arr, int pages)
    {
        int students=1;
        int curr=0;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]+curr > pages)
            {
                students++;
                curr = arr[i];
            }

            else
            {
                curr += arr[i];
            }
        }

        return students;
    }

    int findPages(vector<int>& arr, int n, int m) 
    {
        // Write your code here.
        if (m > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high= accumulate(arr.begin(), arr.end(), 0);

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(f(arr,mid) > m)  low=mid+1;
            else    high=mid-1;
        }

        return low;

    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};