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
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* h1 = new ListNode();    
        ListNode* h2 = new ListNode();
        ListNode* h1_curr = h1; // Pointer         
        ListNode* h2_curr = h2; // Pointer         

        while (head) 
        {
            if (head->val < x) 
            {
                h1_curr->next = new ListNode(head->val);
                h1_curr = h1_curr->next;
            } 
            
            else 
            {
                h2_curr->next = new ListNode(head->val);
                h2_curr = h2_curr->next;
            }

            head = head->next;
        }

        h1_curr->next = h2->next;
        
        ListNode* result = h1->next;
        
        // Clean up the dummy nodes
        delete h1;
        delete h2;

        return result;
    }
};
