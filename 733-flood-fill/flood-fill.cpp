class Solution {
public:
    bool isValid(int r,int c,vector<vector<int>>& image)
    {
        int n = image.size();
        int m = image[0].size();

        if(r>=0 && r<n && c>=0 && c<m)  return true;
        return false;
    }
    void dfs(int row,int col,int old,int newC,
            vector<vector<int>>& image,vector<vector<int>>& ans)
    {
        int n = image.size();
        int m = image[0].size();

        ans[row][col]=newC;

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(isValid(nrow,ncol,image) && image[nrow][ncol]==old 
               && ans[nrow][ncol]!=newC)
            {
                dfs(nrow,ncol,old,newC,image,ans);
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newC) 
    {
        vector<vector<int>> ans=image;
        int old = image[sr][sc];
        dfs(sr,sc,old,newC,image,ans);
        return ans;
    }
};