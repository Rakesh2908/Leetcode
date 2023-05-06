class DisjointSet
{
    vector<int> parent, rank, size;

public:
    // constructor to initialize parent, rank, and size arrays
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        
        // initialize parent array such that each node is its own parent
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // find the parent node of the given node
    int findUPar(int node)
    {
        // if node is its own parent, return node
        if(node == parent[node])
            return node;

        // path compression: set the parent of the current node to its grandparent
        // this flattens the tree and reduces the time complexity of future findUPar calls
        return parent[node] = findUPar(parent[node]);
    }

    // union two sets by their rank
    void UnionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) // if nodes are already in the same set, no need to merge
            return;

        if(rank[pu] < rank[pv]) // if the rank of the parent of u is less than that of the parent of v, attach u to v
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) // if the rank of the parent of v is less than that of the parent of u, attach v to u
        {
            parent[pv] = pu;
        }
        else // if the ranks are equal, attach v to u and increase the rank of u
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // union two sets by their size
    void UnionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) // if nodes are already in the same set, no need to merge
            return;

        if(size[pu] < size[pv]) // if size of set containing u is less than that of set containing v, attach u to v
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else // if size of set containing v is less than or equal to that of set containing u, attach v to u
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        DisjointSet dsu(n);

// Iterate over each pair of stones and merge them if they share a row or a column
        for(int i=0;i<n;i++) 
        {
            for(int j=i+1;j<n;j++) 
            {
                if(stones[i][0]==stones[j][0] || 
                   stones[i][1]==stones[j][1]) 
                {
                    dsu.UnionBySize(i,j);
                }
            }
        }

        // Count the number of connected components
        int num_components = 0;
        for(int i=0;i<n;i++) 
        {
            if(dsu.findUPar(i) == i) 
            {
                num_components++;
            }
        }

        // Calculate the number of stones that can be removed
        int num_removed = n - num_components;

        return num_removed;
    }

};