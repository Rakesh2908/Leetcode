class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)  // If the list is empty or has only one node, no swaps needed
            return head;

        ListNode* temp = new ListNode();  // Create a temporary node to serve as the dummy head

        ListNode* prev = temp;  // Initialize prev pointer to the temporary node
        ListNode* curr = head;  // Initialize curr pointer to the head of the list

        while (curr && curr->next) {
            prev->next = curr->next;          // Update prev's next to point to curr's next
            curr->next = prev->next->next;    // Update curr's next to skip the next node
            prev->next->next = curr;          // Update the next of the node after prev to point to curr

            prev = curr;  // Move prev to curr position (prev now becomes the last node in the swapped pair)
            curr = curr->next;  // Move curr to the next pair's starting position
        }

        return temp->next;  // Return the new head of the linked list after swapping
    }
};
