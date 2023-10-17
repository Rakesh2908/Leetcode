class Solution {
public:
    int lengthLL(ListNode* head) 
    {
        int length = 0;
        while (head) 
        {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || !head->next)
            return head;

        int length = lengthLL(head);  // Calculate the length of the linked list

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur;
        ListNode* nex;

        // Check if there are enough nodes to reverse
        while (length >= k) 
        {
            cur = pre->next;
            nex = cur->next;

            for (int i = 1; i < k; i++) 
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }

            pre = cur;
            length -= k;
        }

        return dummy->next;
    }
};
