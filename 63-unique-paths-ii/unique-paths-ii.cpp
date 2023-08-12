class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& maze) 
    {
        int n = maze[0].size();
        int m = maze.size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        if(maze[m-1][n-1]==1 || maze[0][0]==1)   return 0;
        
        return solve(m-1,n-1,maze,dp);
    }

    int solve(int i,int j,vector<vector<int>>& maze,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0)  return 0;
        if(i>=0 && j>=0 && maze[i][j]==1)   return 0;
      

        if(dp[i][j] != -1)  return dp[i][j];

        int up = solve(i-1,j,maze,dp);
        int left = solve(i,j-1,maze,dp);

        return dp[i][j] = up + left;
    }
};