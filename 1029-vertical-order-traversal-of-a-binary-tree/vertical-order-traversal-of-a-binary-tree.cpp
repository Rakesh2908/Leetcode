class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> vertical; // x, y, set of nodes
        queue<pair<TreeNode*, pair<int, int>>> q; // node, x, y
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            q.pop();

            vertical[x][y].insert(node->val);

            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }

            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (const auto& x_pair : vertical) 
        {
            vector<int> col;

            for (const auto& y_pair : x_pair.second) 
            {
                col.insert(col.end(), 
                            y_pair.second.begin(), y_pair.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};
