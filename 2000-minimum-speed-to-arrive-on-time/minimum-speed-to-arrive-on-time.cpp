class Solution {
public:
    double timeReq(int speed, vector<int>&dist)
    {
        double time = 0.0;

        for(int i=0;i<dist.size();i++)
        {
            double t = (double)dist[i]/speed;

            time += (i==dist.size()-1)?t:ceil(t);
        }
        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int mini=-1;
        int left=1;
        int right=(int)1e7;

        while(left <= right)
        {
            int mid = left + (right-left)/2;

            if(timeReq(mid,dist) <= hour)
            {
                mini = mid;
                right=mid-1;
            }

            else
            {
                left=mid+1;
            }
        }

        return mini;
    }
};