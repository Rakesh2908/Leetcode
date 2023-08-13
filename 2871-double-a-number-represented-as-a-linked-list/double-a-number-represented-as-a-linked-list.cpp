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
    ListNode* reverseL(ListNode* head) 
    {
        ListNode* prev = NULL;

        while(head != NULL)
        {
            ListNode* next = head->next;
            head->next=prev;
            prev=head;
            head=next;
        }

        return prev;
    }

    ListNode* doubleL(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head; // Initialize curr to head

        int carry=0,sum=0;

        while(curr != NULL) // This loop won't run because curr is NULL initially
        {
            sum = carry + (curr->val * 2);
            carry = sum/10;
            sum = sum%10;            

            curr->val=sum;
            prev=curr;
            curr = curr->next;
        }

        if(carry>0)
        {
            prev->next = new ListNode(carry);
        }

        return head; // You should return 'head' instead of 'prev'
    }

    ListNode* doubleIt(ListNode* head) 
    {
        head = reverseL(head);
        head = doubleL(head);

        return reverseL(head);
    }
};
