class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }

            else
            {
                //overlap
                /* 
                for eg {(1,5),{4,7}} = {{1,7}}
                ans.back()[1] = 5;
                intervals[i][0] = 4; // current element
                
                ans.back()[1] = max(5,7); // to get the end time
                */
                if(ans.back()[1] >= intervals[i][0])
                {
                    ans.back()[1] = max(ans.back()[1],intervals[i][1]);
                }
            }
        }

        return ans;
    }
};