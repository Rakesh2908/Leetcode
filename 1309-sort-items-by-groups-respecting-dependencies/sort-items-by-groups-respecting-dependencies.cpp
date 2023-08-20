class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& graph, vector<int>& indegree) 
    {
        vector<int> visited;
        stack<int> s;

        for (const auto& entry : graph) 
        {
            int key = entry.first;
            if (indegree[key] == 0) 
            {
                s.push(key);
            }
        }
        
        while (!s.empty()) 
        {
            int curr = s.top();
            s.pop();
            visited.push_back(curr);
            
            for (int prev : graph[curr]) 
            {
                indegree[prev]--;
                if (indegree[prev] == 0) 
                {
                    s.push(prev);
                }
            }
        }

        return visited.size() == graph.size() ? visited : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) 
    {
        // If an item belongs to zero group, assign it a unique group id.
        int groupId = m;
        for (int i = 0; i < n; i++) 
        {
            if (group[i] == -1) 
            {
                group[i] = groupId++;
            }
        }
        
        // Sort all item regardless of group dependencies.
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) 
        {
            itemGraph[i] = vector<int>();
        }
        
        // Sort all groups regardless of item dependencies.
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(groupId, 0);
        for (int i = 0; i < groupId; ++i) {

            groupGraph[i] = vector<int>();
        }
        
        for (int curr = 0; curr < n; curr++) 
        {
            for (int prev : beforeItems[curr]) 
            {
                // Each (prev -> curr) represents an edge in the item graph.
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;
                
                // If they belong to different groups, add an edge in the group graph.
                if (group[curr] != group[prev]) 
                {
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupIndegree[group[curr]]++;
                }
            }
        }

        // Topological sort nodes in the graph, return an empty array if a cycle exists.
        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
        
        if (itemOrder.empty() || groupOrder.empty()) 
        {
            return vector<int>();
        }
        
        // Items are sorted regardless of groups, we need to differentiate them by the groups they belong to.
        unordered_map<int, vector<int>> orderedGroups;
        for (int item : itemOrder) 
        {
            orderedGroups[group[item]].push_back(item);
        }
        
        // Concatenate sorted items in all sorted groups.
        // [group 1, group 2, ... ] -> [(item 1, item 2, ...), (item 1, item 2, ...), ...]
        vector<int> answerList;
        for (int groupIndex : groupOrder) 
        {
            answerList.insert(answerList.end(), orderedGroups[groupIndex].begin(), orderedGroups[groupIndex].end());
        }
        
        return answerList;
    }
};
