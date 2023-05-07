class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Initialize a stack and a queue
        stack<int> st;
        queue<int> q;

        // Add all the elements from the popped vector to the queue
        for (int num : popped) 
        {
            q.push(num);
        }

        // Loop through each element in the pushed vector
        for (int num : pushed) 
        {
            // Add the current element to the stack
            st.push(num);
            // Keep popping elements from the stack as long as the top element
            // matches the next element in the queue
            while (!st.empty() && !q.empty() && st.top() == q.front()) 
            {
                st.pop();
                q.pop();
            }
        }

        // If the stack and queue are both empty, then all elements were popped
        // in the correct order
        return st.empty() && q.empty();
    }
};
