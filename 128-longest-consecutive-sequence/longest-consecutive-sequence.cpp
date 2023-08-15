class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>s(nums.begin(), nums.end());
        int maxi=1;

        if(nums.size()==0)  return 0;

        for(auto it: s)
        {
            if(!s.count(it-1))
            {
                int len = 1;

                while(s.count(it+len))
                {
                    len++;
                    maxi=max(maxi,len);
                }
            }
        }

        return maxi;
    }
};