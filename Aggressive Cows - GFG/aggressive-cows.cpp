//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool f(vector<int>&nums, int dist, int cows)
    {
        int cntCows=1;
        int last=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-last >= dist)
            {
                cntCows++;
                last=nums[i];
            }
        }
        
        return cntCows>=cows;
    }

    int solve(int n, int cows, vector<int> &nums) 
    {
        // Write your code here
        sort(nums.begin(),nums.end());
        
        int low=1;
        int high=nums[n-1]-nums[0];
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(f(nums,mid,cows))    low=mid+1;
            else    high=mid-1;
        }
        
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends