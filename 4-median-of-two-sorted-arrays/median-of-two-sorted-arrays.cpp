class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size() + nums2.size();
        int ind1 = (n - 1) / 2;
        int ind2 = n / 2;
        int a = -1, b = -1;

        int i = 0, j = 0;
        int cnt = 0;

        while (i < nums1.size() && j < nums2.size()) 
        {
            if (nums1[i] <= nums2[j]) 
            {
                if (cnt == ind1) a = nums1[i];
                if (cnt == ind2) b = nums1[i];
                i++;
            } 

            else 
            {
                if (cnt == ind1) a = nums2[j];
                if (cnt == ind2) b = nums2[j];
                j++;
            }
            cnt++;
        }

        while (i < nums1.size() && cnt <= ind2) 
        {
            if (cnt == ind1) a = nums1[i];
            if (cnt == ind2) b = nums1[i];
            i++;
            cnt++;
        }

        while (j < nums2.size() && cnt <= ind2) 
        {
            if (cnt == ind1) a = nums2[j];
            if (cnt == ind2) b = nums2[j];
            j++;
            cnt++;
        }

        if (n % 2 == 1) return (double)b;
        
        return ((double)a + (double)b) / 2.0;
    }
};
