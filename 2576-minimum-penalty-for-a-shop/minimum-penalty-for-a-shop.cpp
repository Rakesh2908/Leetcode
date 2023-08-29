class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int curPenalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = curPenalty;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); i++) 
        {
            if (customers[i] == 'Y')    curPenalty--;
            
            else    curPenalty++;

            if (curPenalty < minPenalty) 
            {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};