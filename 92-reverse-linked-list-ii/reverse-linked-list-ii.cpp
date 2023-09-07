class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) {
            return nullptr;
        }

        ListNode* cur = head;
        ListNode* prev = nullptr;

        // Move the two pointers until they reach the proper starting point
        // in the list.
        while (m > 1) {
            prev = cur;
            cur = cur->next;
            m--;
            n--;
        }

        // The two pointers that will fix the final connections.
        ListNode* con = prev;
        ListNode* tail = cur;

        ListNode* third = nullptr;
        
        // Iteratively reverse the nodes until n becomes 0.
        while (n > 0) {
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
            n--;
        }

        // Adjust the final connections as explained in the algorithm.
        if (con != nullptr) {
            con->next = prev;
        } else {
            head = prev;
        }

        tail->next = cur;
        return head;
    }
};
