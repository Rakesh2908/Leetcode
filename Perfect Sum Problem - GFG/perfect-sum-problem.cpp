//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9 + 7;

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return findWaysUtil(n-1,sum,arr,dp);
	}
	
	int findWaysUtil(int ind, int target, int arr[], vector<vector<int>> &dp)
	{
        if(ind == 0)
        {
            if(target==0 && arr[0]==0)  return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
            
        int notTaken = findWaysUtil(ind-1,target,arr,dp)%mod;
        
        int taken = 0;
        if(arr[ind]<=target)
            taken = findWaysUtil(ind-1,target-arr[ind],arr,dp)%mod;
            
        return dp[ind][target]= (notTaken%mod + taken%mod)%mod;
    }
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends