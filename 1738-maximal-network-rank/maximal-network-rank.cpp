class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int,int>mp;
        vector<vector<bool>> linked(n, vector<bool>(n, false)); 

        for (auto it: roads) 
        {
            mp[it[0]]++;
            mp[it[1]]++;
            linked[it[0]][it[1]] = linked[it[1]][it[0]] = true;
        }

        int maxi = 0;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j)
             {
                int rank = mp[i] + mp[j];

                //if there is already a link bw i and j
                if (linked[i][j]) 
                {
                    rank--; 
                }

                maxi = max(maxi, rank);
            }
        }

        return maxi;
    }
};
