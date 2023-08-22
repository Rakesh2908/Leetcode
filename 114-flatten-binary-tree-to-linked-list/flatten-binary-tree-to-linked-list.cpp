class Solution {
public:
    vector<int> ans;

    void preorder(TreeNode* root) {
        if (!root) return;

        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void flatten(TreeNode* root) {
        if (!root) return;

        // Step 1: Traverse the tree and store elements in the ans vector.
        preorder(root);

        // Step 2: Insert all elements to the right of the root from the ans vector.
        TreeNode* current = root;
        for (int i = 1; i < ans.size(); ++i) 
        {
            current->right = new TreeNode(ans[i]);
            current->left = nullptr; // Set left to nullptr for each inserted node.
            current = current->right;
        }
    }
};
