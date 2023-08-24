class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) 
    {
        int n = cardPoints.size();

        int front[k + 1];
        int back[k + 1];

        //Intialize 0th index in both the arrays
        front[0] = back[0] = 0;

        for (int i = 0; i < k; i++) 
        {
            front[i + 1] = cardPoints[i] + front[i];
            back[i + 1] = cardPoints[n - i -1] + back[i];
        }

        int maxi = 0;
        // Each i represents the number of cards we take from the front.
        for (int i = 0; i <= k; i++) 
        {
            int curr = front[i] + back[k - i];
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};
