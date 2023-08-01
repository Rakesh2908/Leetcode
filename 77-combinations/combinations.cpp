class Solution {
public:
    void f(int i,int k,vector<int> &arr, vector<int> &temp,
          vector<vector<int>> &ans)
    {
        if(arr.size()==0 || k>arr.size())   return;

        if(k==0)
        {
            ans.push_back(temp);
        }

        for(int j=i;j<arr.size();j++)
        {
            temp.push_back(arr[j]);
            f(j+1,k-1,arr,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(i+1);
        }

        vector<int> temp;
        vector<vector<int>> ans;

        f(0,k,arr,temp,ans);

        return ans;
    }
};