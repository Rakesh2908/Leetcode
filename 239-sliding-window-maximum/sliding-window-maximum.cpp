class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        //we store the indices in decreasing order of their values
        deque<int>dq;
        vector<int>ans;

        for(int i=0;i<size(nums);i++)
        {
            //we pop prev out of bound elements
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            
            //we have to remove smaller elements when compared to the
            //present element which are stored ate the back of deque
            while(!dq.empty() && nums[dq.back()]<=nums[i])  
                dq.pop_back();            
            
            dq.push_back(i);

            //k-1 is the last index of the first window and dq.front() always
            //contains the max value in that window
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};