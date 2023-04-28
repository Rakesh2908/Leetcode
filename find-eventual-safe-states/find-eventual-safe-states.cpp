class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        vector<int> color(n);
        vector<int> res;

        for (int i = 0; i < n; i++) 
        {
            if (dfs(i, graph, color)) 
            {
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color) 
    {
        if (color[u] > 0) 
        {
            return color[u] == 2;
        }

        color[u] = 1;

        for (int v : graph[u]) 
        {
            if (color[v] == 2) 
            {
                continue;
            }

            if (color[v] == 1 || !dfs(v, graph, color)) 
            {
                return false;
            }
        }
        
        color[u] = 2;
        return true;
    }
};
