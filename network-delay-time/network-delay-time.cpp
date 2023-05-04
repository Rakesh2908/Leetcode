class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // Initialize adjacency list
        vector<pair<int, int>> adj[n+1];
        for (auto& time : times) 
        {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        
        // Initialize distance array
        int dist[n+1];
        for (int i = 1; i <= n; i++) 
        {
            dist[i] = INT_MAX;
        }
        
        // Dijkstra's algorithm
        priority_queue< pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        
        while (!pq.empty()) 
        {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& edge : adj[u]) 
            {
                int v = edge.first, w = edge.second;
                if (dist[u] + w < dist[v]) 
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Find maximum distance
        int max_dist = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (dist[i] == INT_MAX) 
            {
                return -1; // Unreachable node
            }
            max_dist = max(max_dist, dist[i]);
        }
        
        return max_dist;
    }
};