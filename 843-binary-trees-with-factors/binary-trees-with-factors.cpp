class Solution {
public:
    int mod = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long int> mp;

        for (auto it : arr) mp[it] = 1; 

        for (int i = 1; i < arr.size(); i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (arr[i] % arr[j] == 0) 
                {
                    int quotient = arr[i] / arr[j];

                    if (mp.find(quotient) != mp.end()) 
                    {
                        mp[arr[i]] += mp[arr[j]] * mp[quotient];
                        mp[arr[i]] %= mod;
                    }
                }
            }
        }

        long long sum = 0;
        for (auto it : mp) sum = (sum + it.second) % mod;

        return int(sum);
    }
};
