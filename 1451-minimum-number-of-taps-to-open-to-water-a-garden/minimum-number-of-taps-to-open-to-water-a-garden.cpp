class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> max_range(n + 1, 0);
        
        for (int i = 0; i < ranges.size(); i++) 
        {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            max_range[left] = max(max_range[left], right - left);
        }
        
        int start = 0;
        int end = 0;
        int step = 0;
        
        while (end < n) 
        {
            step++;

            int new_end = end;
            
            for (int i = start; i <= end; i++) 
            {
                new_end = max(new_end, i + max_range[i]);
            }

            if (new_end == end) 
            {
                return -1;
            }

            start = end;
            end = new_end;
        }
        
        return step;
    }
};
