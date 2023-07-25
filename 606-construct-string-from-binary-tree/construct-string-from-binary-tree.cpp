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
class Solution {
public:

    void f(TreeNode* root, string &s)
    {
        if (!root)
            return;
            
        s += to_string(root->val);

        if (!root->left && !root->right)
            return;

        s += '(';
        f(root->left, s);
        s += ')';

        if (root->right) 
        {
            s += '(';
            f(root->right, s);
            s += ')';
        }
    }

    string tree2str(TreeNode* root) 
    {
        string s;
        f(root,s);
        return s;
    }
};