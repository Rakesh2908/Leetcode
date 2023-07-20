class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int len=1;// Initialize the chain length to 1 since at least one pair is always possible
        int prev=pairs[0][1];

        for(int i=1;i<n;i++)
        {
            if(prev < pairs[i][0])
            {
                len++;
                prev = pairs[i][1];
            }
        }

        return len;
    }
};