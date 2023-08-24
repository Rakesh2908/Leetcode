/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    pair<int, int> fun(TreeNode* root)
    {
        if(root == NULL)
            return {0, 0};
        
        pair<int, int> l = fun(root->left);
        pair<int, int> r = fun(root->right);

        int take = root->val + l.second + r.second;
        int notTake = max(l.first, l.second) + max(r.first, r.second);

        return {take, notTake};
    }

    int rob(TreeNode* root) 
    {
        pair<int, int> ans = fun(root);

        return max(ans.first, ans.second);
    }
};