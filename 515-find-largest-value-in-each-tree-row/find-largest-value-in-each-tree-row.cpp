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
    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                
                if(node->left != NULL) 
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
    vector<int> largestValues(TreeNode* root) 
    {
        levelOrder(root);
        vector<int>res;
        for(auto vec: ans)
        {
            int ele = *max_element(vec.begin(),vec.end());
            res.push_back(ele);
        }

        return res;
    }
};