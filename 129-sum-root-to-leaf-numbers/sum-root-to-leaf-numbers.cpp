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
    int f(TreeNode* root, int sum)
    {
        if(!root)   return 0; 

        sum = 10*sum + root->val;

        if(!root->left && !root->right) return sum; 

        int left = f(root->left,sum);
        int right = f(root->right,sum);

        return left+right;
    }

    int sumNumbers(TreeNode* root) 
    { 
        return f(root,0);
    }
};