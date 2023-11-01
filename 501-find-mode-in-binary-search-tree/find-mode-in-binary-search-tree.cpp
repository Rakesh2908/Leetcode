class Solution {
public:
    vector<int> ans;

    void Inorder(TreeNode* root, unordered_map<int, int>& count) 
    {
        if (root == NULL)
            return;

        Inorder(root->left, count);
        count[root->val]++;
        Inorder(root->right, count);
    }

    vector<int> findMode(TreeNode* root) 
    {
        if (root == nullptr)
            return ans;

        unordered_map<int, int> count;
        Inorder(root, count);

        int maxCount = 0;
        for (const auto& pair : count) 
        {
            if (pair.second > maxCount) 
            {
                maxCount = pair.second;
                ans.clear();
                ans.push_back(pair.first);
            } 
            
            else if (pair.second == maxCount) 
            {
                ans.push_back(pair.first);
            }
        }
        
        return ans;
    }
};
