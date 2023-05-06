//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(n);
        
        int sum=0;
        
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v))
            {
                sum += wt;
                ds.UnionBySize(u,v);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends