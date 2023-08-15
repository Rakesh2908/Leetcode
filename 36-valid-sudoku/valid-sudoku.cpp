class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // Check each row for validity
        for (int i = 0; i < 9; i++) 
        {
            vector<int> rowFreq(9, 0);

            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] != '.') 
                {
                    // Convert char to integer representation (1 to 9)
                    int num = board[i][j] - '1';
                    rowFreq[num]++;

                    if (rowFreq[num] == 2) 
                    {
                        return false; // Violation found in row
                    }
                }
            }
        }
        
        // Check each column for validity
        for (int j = 0; j < 9; j++) 
        {
            vector<int> colFreq(9, 0);

            for (int i = 0; i < 9; i++) 
            {
                if (board[i][j] != '.') 
                {
                    // Convert char to integer representation (1 to 9)
                    int num = board[i][j] - '1';
                    colFreq[num]++;

                    if (colFreq[num] == 2) 
                    {
                        return false; // Violation found in column
                    }
                }
            }
        }
        
        // Check each 3x3 sub-grid for validity
        for (int i = 0; i < 9; i += 3) 
        {
            for (int j = 0; j < 9; j += 3) 
            {
                vector<int> subgridFreq(9, 0);

                for (int x = i; x < i + 3; x++) 
                {
                    for (int y = j; y < j + 3; y++) 
                    {
                        if (board[x][y] != '.') 
                        {
                        // Convert char to integer representation (1 to 9)
                            int num = board[x][y] - '1';
                            subgridFreq[num]++;

                            if (subgridFreq[num] == 2) 
                            {
                                return false; // Violation found in sub-grid
                            }
                        }
                    }
                }
            }
        }
        
        return true; // No violations found, Sudoku is valid
    }
};