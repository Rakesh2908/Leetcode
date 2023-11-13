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

    void f(int col, vector<string>&board, int &cnt, int n)
    {
        if(col==n)
        {
            cnt++;
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                //pick
                board[row][col]='Q';
                f(col+1,board,cnt,n);
                //not pick
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) 
    {
        int cnt=0;
        vector<string> board(n, string(n, '.'));  
        f(0, board, cnt, n);
        return cnt;
    }
};