#include <bits/stdc++.h>

class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) 
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n+1,1);

        for (int i = 0; i <= n; i++) 
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) 
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) 
    {
        int up = findPar(u);
        int vp = findPar(v);

        if (up == vp)
            return;

        if (rank[up] < rank[vp]) 
        {
            parent[up] = vp;
        } 
        
        else if (rank[up] > rank[vp]) 
        {
            parent[vp] = up;
        } 
        
        else 
        {
            parent[up] = vp;
            rank[vp]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int up = findPar(u);
        int vp = findPar(v);

        if(up == vp)
            return;

        if(size[up] < size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }

        else
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size(); 

        if(n==1)
            return 0;

        // val -> row,col
        unordered_map<int,pair<int,int>> mp;

        DisjointSet ds(n*n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[grid[i][j]] = {i,j};
            }
        }

        int time=0;

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};

        while(ds.findPar(0) != ds.findPar(n*n - 1))
        {
            auto node = mp[time];
            int r = node.first;
            int c = node.second;

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]<=time)
                {
                    ds.unionBySize(r*n + c, nr*n + nc);
                }
            }

            time++;
        }

        return time-1;
    }
};