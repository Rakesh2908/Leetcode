//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution {
public:
    int f(int idx, int arr[], int n, vector<int>& dp) 
    {
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int notTake = f(idx - 1, arr, n, dp);
        int take = arr[idx] + f(idx - 2, arr, n, dp);

        return dp[idx] = max(take, notTake);
    }

    int FindMaxSum(int arr[], int n) 
    {
        vector<int> dp(n, -1);
        return f(n - 1, arr, n, dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends