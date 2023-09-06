class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* cur = root;
        int N = 0;
        while (cur != nullptr) {
            cur = cur->next;
            N++;
        }

        int width = N / k, rem = N % k;

        vector<ListNode*> ans(k, nullptr);
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode* head = new ListNode(0);
            ListNode* write = head;
            for (int j = 0; j < width + (i < rem ? 1 : 0); ++j) {
                if (cur != nullptr) {
                    write->next = new ListNode(cur->val);
                    cur = cur->next;
                }
                write = write->next;
            }
            ans[i] = head->next;
        }
        return ans;
    }
};
