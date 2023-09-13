class Solution {
public:
    int candy(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>left(n,1);
        int right=1;

        //checking from left
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                left[i+1]=left[i]+1;
            }
        }    

        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                right++;
                left[i]=max(left[i],right);
            }

            else 
                right=1;
        }

        int sum = accumulate(left.begin(),left.end(),0);
        return sum;
    }
};