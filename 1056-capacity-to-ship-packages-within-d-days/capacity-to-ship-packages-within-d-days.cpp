class Solution {
public:
    int countDays(vector<int>& weights, int capacity) 
    {
        int days = 1;
        int currentCapacity = 0;

        for (int weight : weights) 
        {
            if (currentCapacity + weight > capacity) 
            {
            // If adding this weight exceeds the capacity, start a new day
                days++;
                currentCapacity = weight;
            } 

            else 
            {
                currentCapacity += weight;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) 
        {
            int mid = low + (high - low) / 2;

// Check if the current capacity can ship all packages within the given days
            if (countDays(weights, mid) > days)
            {
            // If it takes more days than allowed, increase the capacity
                low = mid + 1;
            } 

            else 
            {
            // If it takes fewer or equal days, try to minimize the capacity
                high = mid;
            }
        }

        return low;
    }
};
