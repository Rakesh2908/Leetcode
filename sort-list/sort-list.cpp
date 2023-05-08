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
    ListNode* sortList(ListNode* head) {
        // base case: empty or single node list is already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // create a vector to store the values in the list
        vector<int> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
        
        // sort the values in ascending order
        sort(values.begin(), values.end());
        
        // create a dummy head node for the sorted list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // create a new node for each sorted value and attach it to the sorted list
        for (int value : values) {
            current->next = new ListNode(value);
            current = current->next;
        }
        current->next = nullptr; // set the end of the sorted list to null
        
        return dummy->next; // skip the dummy head node and return the actual head of the sorted list
    }
};
