//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int cnt = 0;

        while (n > 1) // Change the loop condition
        {
            if (n % 2 == 0) 
                n /= 2; // Double the number
                
            else 
                n -= 1; // Subtract one
            
            cnt++;
        }

        return cnt + 1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends