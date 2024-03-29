/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        // Close the linked list into the ring
        ListNode* old_tail = head;
        int n;
        for (n = 1; old_tail->next != nullptr; n++)
            old_tail = old_tail->next;
        old_tail->next = head;

        // Find new tail: (n - k % n - 1)th node
        // and new head: (n - k % n)th node
        ListNode* new_tail = head;
        for (int i = 0; i < n - k % n - 1; i++)
            new_tail = new_tail->next;
        ListNode* new_head = new_tail->next;

        // Break the ring
        new_tail->next = nullptr;

        return new_head;    
    }
};