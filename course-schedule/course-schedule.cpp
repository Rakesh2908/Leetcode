class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // Initialize the adjacency list and the in-degree vector
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses);

        for (auto p : prerequisites) 
        {
            int u = p[1], v = p[0];
            adjList[u].push_back(v);

            inDegree[v]++;
        }
        
        // Initialize the queue with all nodes having zero in-degree
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++) 
        {
            if (inDegree[i] == 0) 
            {
                q.push(i);
            }
        }
        
        // Perform the Kahn's algorithm
        vector<int> res;

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            res.push_back(u);

            for (int v : adjList[u]) 
            {
                inDegree[v]--;

                if (inDegree[v] == 0) 
                {
                    q.push(v);
                }
            }
        }
        
        // Check if all nodes have been visited
        if (res.size() != numCourses) 
        {
            return false;
        }
        
        // Return the result
        return true;
    }
};