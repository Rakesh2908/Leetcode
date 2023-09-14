class Solution {
private:
    unordered_map<string, list<string>> flightMap;
    list<string> result;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Build the graph
        for (const vector<string>& ticket : tickets) {
            string origin = ticket[0];
            string dest = ticket[1];
            flightMap[origin].push_back(dest);
        }

        // Step 2: Sort the destinations lexicographically
        for (auto& [origin, destinations] : flightMap) {
            destinations.sort();
        }

        // Step 3: Perform post-order DFS starting from JFK
        DFS("JFK");

        // Convert the result list to a vector and return
        return vector<string>(result.begin(), result.end());
    }

private:
    void DFS(string origin) {
        if (flightMap.count(origin)) {
            list<string>& destList = flightMap[origin];
            while (!destList.empty()) {
                string dest = destList.front();
                destList.pop_front();
                DFS(dest);
            }
        }
        result.push_front(origin);
    }
};
