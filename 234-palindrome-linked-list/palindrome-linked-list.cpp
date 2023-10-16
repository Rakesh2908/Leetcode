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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;

        ListNode *temp=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;

        return temp;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
            return true;

        ListNode *slow=head, *fast=head;

        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reverse(slow->next);
        slow=slow->next;
        fast=head;

        while(slow)
        {
            if(slow->val != fast->val)
                return false;
            
            slow=slow->next;
            fast=fast->next;
        }

        return true;
    }
};