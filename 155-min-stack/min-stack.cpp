class MinStack {
public:
    stack<int> st;       
    vector<int> ans;    
    
    MinStack() {
       
    }
    
    void push(int val) {
        st.push(val);
        ans.push_back(val);
    }
    
    void pop() {
        st.pop();
        ans.pop_back();  
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int mini = *min_element(ans.begin(), ans.end());
        return mini;   
    }
};
