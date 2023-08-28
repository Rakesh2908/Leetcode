class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> mat(n, vector<int>(n));
        int num = 1;

        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;

        while (num <= n * n) 
        {
            for (int j = colBegin; j <= colEnd; ++j) 
            {
                mat[rowBegin][j] = num++;
            }
            ++rowBegin;

            for (int j = rowBegin; j <= rowEnd; ++j) 
            {
                mat[j][colEnd] = num++;
            }
            --colEnd;

            for (int j = colEnd; j >= colBegin; --j) 
            {
                mat[rowEnd][j] = num++;
            }
            --rowEnd;

            for (int j = rowEnd; j >= rowBegin; --j) 
            {
                mat[j][colBegin] = num++;
            }
            ++colBegin;
        }

        return mat;
    }
};
