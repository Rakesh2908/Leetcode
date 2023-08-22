class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int n = board.size();
        int m = board[0].size();

        //given coordinates
        int ro = click[0];
        int co = click[1];

        //if there is mine, mark it as revealed and return board 
        if(board[ro][co]=='M')
        {
            board[ro][co]='X';
            return board;
        }

        //8 directions
        int dr[]={0,0,1,-1,1,-1,1,-1};
        int dc[]={1,-1,0,0,1,-1,-1,1};    

        queue<pair<int,int>>q;
        q.push({ro,co});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            //count num of mines adjacent to {r,c}
            int cnt=0;

            for(int i=0;i<8;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                //if adjacent is a mine, increase the count
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='M')
                {
                    cnt++;
                }
            }

            //if it has adjacent mines, update it by no of mines around it
            if(cnt>0)
            {
                board[r][c]=cnt+'0';
            }

            //else it is a blank revealed square
            else
            {
                board[r][c]='B';

                for(int i=0;i<8;i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='E')
                    {
                        q.push({nr,nc});
                        board[nr][nc]='B';
                    }
                }
            }
        }

        return board;
    }
};