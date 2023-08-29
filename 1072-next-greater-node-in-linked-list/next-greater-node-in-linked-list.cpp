/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> result;
        stack<pair<int, int>> stack; // Pair of value and index
        
        int index = 0;
        while (head) {
            while (!stack.empty() && stack.top().first < head->val)
            {
                result[stack.top().second] = head->val;
                stack.pop();
            }
            
            stack.push({head->val, index});
            result.push_back(0); // Placeholder for the next larger element
            index++;
            
            head = head->next;
        }
        
        return result;
    }
};
