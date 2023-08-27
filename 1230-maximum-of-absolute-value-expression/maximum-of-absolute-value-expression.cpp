class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int maxSum = 0;
        
        for (int p1 : {1, -1}) 
        {
            for (int p2 : {1, -1}) 
            {
                int minVal = p1 * arr1[0] + p2 * arr2[0] + 0;
                
                for (int i = 1; i < n; ++i) 
                {
                    int currVal = p1 * arr1[i] + p2 * arr2[i] + i;
                    
                    maxSum = max(maxSum, currVal - minVal);
                    minVal = min(minVal, currVal);
                }
            }
        }
        
        return maxSum;
    }
};
