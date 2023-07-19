class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
        int ans=0;

        if(startValue==target)  return 0;

        //instead of going from startvalue to target we do it reverse
        while(startValue < target)
        {
            if(target%2==1)
            {
                ans++;
                target++;
            }

            target /= 2;
            ans++;
        }

        return ans + (startValue-target);
    }
};