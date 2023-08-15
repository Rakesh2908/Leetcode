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
    ListNode* createLinkedList(vector<int>& nums) 
    {
        ListNode* dummy = new ListNode(); // Create a dummy node to start the list
        ListNode* current = dummy; // Pointer to the current node
        
        for (int num : nums) {
            current->next = new ListNode(num); // Create a new node with the current number
            current = current->next; // Move the current pointer forward
        }
        
        return dummy->next; // Return the actual head of the linked list
    }

    ListNode* partition(ListNode* head, int x) 
    {
        vector<int>temp;
        ListNode* curr=head;

        while(curr)
        {
            if(curr->val < x)
            {
                temp.push_back(curr->val);
            }

            curr=curr->next;
        }

        curr = head;

        while(curr)
        {
            if(curr->val >= x)
            {
                temp.push_back(curr->val);
            }

            curr=curr->next;
        }

        return createLinkedList(temp);
    }
};