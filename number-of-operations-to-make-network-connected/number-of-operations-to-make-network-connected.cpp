class DisjointSet
{
    vector<int>parent,rank,size;
    
    public:
    
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void UnionByRank(int u,int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        
        if(pu==pv)  
            return;
            
        if(rank[pu] < rank[pv])
        {
            parent[pu]=pv;
        }
        
        else if(rank[pv] < rank[pu])
        {
            parent[pv]=pu;
        }
        
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    
    void UnionBySize(int u,int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        
        if(pu==pv)  
            return;
            
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.size() < n - 1) 
            return -1;
        
        DisjointSet ds(n);
        for (auto& c : connections) 
        {
            ds.UnionBySize(c[0], c[1]);
        }
        
        int components = 0;
        for (int i = 0; i < n; i++) 
        {
            if (ds.findUPar(i) == i) 
            {
                components++;
            }
        }
        
        return components - 1;
    }
};


