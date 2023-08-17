class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (head == nullptr) return nullptr; // Base case

        vector<int> nums; 
        while (head) 
        {
            nums.push_back(head->val);
            head = head->next;
        }

        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
