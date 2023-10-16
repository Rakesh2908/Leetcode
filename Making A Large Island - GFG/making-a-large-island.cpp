//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++
class Solution {
private:
    const vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int color) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = color;
        int size = 1;
        
        for (const auto& direction : directions) {
            size += dfs(grid, i + direction.first, j + direction.second, color);
        }
        
        return size;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxIslandSize = 0;
        int color = 2;  // Start with 2 because 0 and 1 are used for unvisited and water respectively
        unordered_map<int, int> islandSizes;  // Map to store island sizes
        
        // DFS to find and label islands, and store their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int islandSize = dfs(grid, i, j, color);
                    islandSizes[color] = islandSize;
                    maxIslandSize = max(maxIslandSize, islandSize);
                    ++color;
                }
            }
        }
        
        // Check each 0 cell and calculate the maximum island size by temporarily changing 0 to 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> colors;
                    int currIslandSize = 1;  // 1 because we're changing this cell to 1 temporarily
                    for (const auto& direction : directions) {
                        int ni = i + direction.first;
                        int nj = j + direction.second;
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
                            colors.insert(grid[ni][nj]);
                        }
                    }
                    for (const auto& color : colors) {
                        currIslandSize += islandSizes[color];
                    }
                    maxIslandSize = max(maxIslandSize, currIslandSize);
                }
            }
        }
        
        return maxIslandSize;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends