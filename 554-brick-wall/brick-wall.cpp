class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        int ans=0;   
        int maxi=0;//stores the max gaps column wise
        unordered_map<int,int>m;

        for(int i=0;i<wall.size();i++)
        {
            int sum=0;

            //we are not considering the last element because it is and 
            //edge case
            for(int j=0;j<wall[i].size()-1;j++)
            {
                sum += wall[i][j];
                m[sum]++;
                maxi=max(maxi,m[sum]);
            }
        }

        return wall.size()-maxi;//cross bricks=no.of rows-gaps
    }
};