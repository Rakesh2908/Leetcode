class Solution {
private:
    vector<TreeNode*> tree;

    void inorder(TreeNode* root) 
    {
        if (root == NULL)
            return;

        inorder(root->left);
        tree.push_back(root);
        inorder(root->right);
    }

    TreeNode* solve(int st, int en) 
    {
        if (st > en)
            return NULL;

        int mid = (st + en) / 2;
        TreeNode* node = tree[mid];

        node->left = solve(st, mid - 1);
        node->right = solve(mid + 1, en);

        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        inorder(root);
        return solve(0, tree.size() - 1);
    }
};
