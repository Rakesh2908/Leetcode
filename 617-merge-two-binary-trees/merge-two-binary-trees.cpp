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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1 && !root2)    return NULL;

        int val1=0,val2=0;

        if(root1)   val1=root1->val;
        if(root2)   val2=root2->val;

        TreeNode* root = new TreeNode(val1+val2);

        if(root1 && root2)
        {
            root->left = mergeTrees(root1->left,root2->left);
            root->right = mergeTrees(root1->right,root2->right);
        }

        else if(root1)
        {
            root->left = mergeTrees(root1->left,NULL);
            root->right = mergeTrees(root1->right,NULL);
        }

        else if(root2)
        {
            root->left = mergeTrees(NULL,root2->left);
            root->right = mergeTrees(NULL,root2->right);
        }

        return root;
    }
};