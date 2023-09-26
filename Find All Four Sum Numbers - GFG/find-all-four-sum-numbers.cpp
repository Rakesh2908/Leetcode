//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        // Your code goes here
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) 
        {
            return result; // Invalid input, return an empty result
        }

        sort(nums.begin(), nums.end()); // Sort the input array in ascending order

        for (int i = 0; i < n - 3; i++) 
        {
            if (i > 0 && nums[i] == nums[i - 1]) 
            {
                continue; // Skip duplicate elements to avoid duplicate quadruplets
            }

            for (int j = i + 1; j < n - 2; j++) 
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                {
                    continue; // Skip duplicate elements to avoid duplicate quadruplets
                }

                int left = j + 1; // Pointer for the element after nums[j]
                int right = n - 1; // Pointer for the last element

                while (left < right) 
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right]; // Calculate the current sum

                    if (sum == target) 
                    {
                        // Found a quadruplet that sums up to the target
                        result.push_back({nums[i], nums[j], 
                                            nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicate elements to avoid duplicate quadruplets
                        while (left<right &&nums[left] == nums[left - 1]) 
                        {
                            left++;
                        }

                        // Skip duplicate elements to avoid duplicate quadruplets
                        while (left<right &&nums[right]==nums[right + 1]) 
                        {
                            right--;
                        }
                    } 
                    
                    else if (sum < target) {
                        left++;
                    } 
                    
                    else {
                        right--;
                    }
                }
            }
        }

        return result; // Return the vector of quadruplets
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends