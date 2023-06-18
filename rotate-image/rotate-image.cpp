class Solution {
public:
    void rotate(vector<vector<int>>& A) 
    {
        int n = A.size();

    // Step 1: Taking Transpose of the matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            // Swap elements at (i, j) and (j, i)
            swap(A[i][j], A[j][i]);
        }
    }

    // Step 2: Flipping the matrix horizontally
    int j = 0;
    while(j < n/2)
    {
        for(int i = 0; i < n; i++)
        {
            // Swap elements at (i, j) and (i, n-j-1)
            swap(A[i][j], A[i][n-j-1]);
        }
        j++;
    }
    }
};