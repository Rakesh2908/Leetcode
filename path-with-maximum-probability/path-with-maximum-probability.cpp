class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pair<int, double>>> adjList(n);

        for (int i = 0; i < edges.size(); i++) 
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }

        vector<double> dist(n, 0);
        dist[start] = 1;

        //max-heap
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1, start));

        while (!pq.empty()) 
        {
            pair<double, int> curr = pq.top();
            pq.pop();

            int u = curr.second;
            double p = curr.first;

            if (u == end) 
            {
                return dist[end];
            }

            for (int i = 0; i < adjList[u].size(); i++) 
            {
                int v = adjList[u][i].first;
                double w = adjList[u][i].second;

                if (dist[u] * w > dist[v]) 
                {
                    dist[v] = dist[u] * w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return 0;

    }
};