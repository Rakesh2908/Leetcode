class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next)
            return true;

        string s = "", t = "";
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) 
        {
            s += to_string(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the length is odd, move slow pointer one step forward
        if (fast)
            slow = slow->next;

        while (slow) 
        {
            t += to_string(slow->val);
            slow = slow->next;
        }

        // Reverse t and compare with s
        reverse(t.begin(), t.end());

        return s == t;
    }
};
