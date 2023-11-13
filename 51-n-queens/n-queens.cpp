class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n)
    {
        int dr = row;
        int dc = col;

        //top left (row and col both decreses)
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row--;
            col--;
        }

        row=dr;
        col=dc;

        //(left) only col decreases
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }

        row=dr;
        col=dc;

        //bottom left(row increases and col decreases)
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;

            col--;
            row++;
        }

        return true;
    }

    void f(int col, vector<string>&board, vector<vector<string>>& ans, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                //pick
                board[row][col]='Q';
                f(col+1,board,ans,n);
                //not pick
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  
        f(0, board, ans, n);
        return ans;
    }

};