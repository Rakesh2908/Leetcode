class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<int> degree(n, 0); // Store the degree of each city
        vector<vector<bool>> linked(n, vector<bool>(n, false)); // Store the connection status between cities

        for (const auto& road : roads) 
        {
            degree[road[0]]++;
            degree[road[1]]++;
            linked[road[0]][road[1]] = linked[road[1]][road[0]] = true;
        }

        int maxi = 0;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j)
             {
                int rank = degree[i] + degree[j];

                if (linked[i][j]) 
                {
                    rank--; // Deduct 1 from rank if cities are connected
                }

                maxi = max(maxi, rank);
            }
        }

        return maxi;
    }
};
