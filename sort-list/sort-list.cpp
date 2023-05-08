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
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) 
        {
            return head;
        }
        
        vector<int> ans;
        ListNode* curr = head;
        while (curr != nullptr) 
        {
            ans.push_back(curr->val);
            curr = curr->next;
        }
        
        sort(begin(ans), end(ans));
        
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        for (int answ : ans) 
        {
            dummy->next = new ListNode(answ);
            dummy = dummy->next;
        }
        dummy->next = nullptr;
        
        return res->next;
    }
};