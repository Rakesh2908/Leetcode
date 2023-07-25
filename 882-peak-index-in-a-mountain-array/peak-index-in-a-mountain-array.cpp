class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int s=1,e=n-2;

        while(s<=e)
        {
            int m = s + (e-s)/2;

            if(arr[m]>arr[m-1] && arr[m]>arr[m+1])
                return m;
            else if(arr[m-1]>arr[m])
                e = m-1;
            else
                s = m+1;
        }
        return -1;
    }
};