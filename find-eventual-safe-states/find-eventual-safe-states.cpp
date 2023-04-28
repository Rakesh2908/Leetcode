class Solution {
 public:
   vector<int> eventualSafeNodes(vector<vector<int>>& graph)
   {
        int n=graph.size();
        
        // creating array to store the indegree
        vector<int>indegree(n,0); 

// we will be reversing the edges so that we can apply toposort as toposort work on indegree.
        vector<vector<int>>adjrev(n); 
        
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int>safenodes;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            safenodes.push_back(node);
            
            for(auto it:adjrev[node])
            {
                indegree[it]--;

                if(indegree[it]==0) 
                    q.push(it);
            }
            
        }
        
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};