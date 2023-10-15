class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next)
            return true;

        ListNode *slow = head, *fast = head;
        stack<int> st;

        while (fast && fast->next) 
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the length is odd, move slow pointer one step forward
        if (fast)
            slow = slow->next;

        while (slow) 
        {
            int top = st.top();
            st.pop();
            if (top != slow->val)
                return false;
            slow = slow->next;
        }

        return true;
    }
};
