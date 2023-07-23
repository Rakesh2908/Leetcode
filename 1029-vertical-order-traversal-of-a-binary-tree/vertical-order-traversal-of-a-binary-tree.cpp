class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> nodes; // x, y, set of nodes
        queue<pair<TreeNode*, pair<int, int>>> todo; // node, x, y
        todo.push({root, {0, 0}}); // push root node with (x, y) position

        while (!todo.empty()) 
        { // traverse the tree
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first; // current node
            int x = p.second.first, y = p.second.second; // coordinates

            nodes[x][y].insert(node->val); // store node value based on (x, y) position

            if (node->left) 
            { // if left child exists
                todo.push({node->left, {x - 1, y + 1}}); // enqueue left child with updated position
            }

            if (node->right) 
            { // if right child exists
                todo.push({node->right, {x + 1, y + 1}}); // enqueue right child with updated position
            }
        }

        vector<vector<int>> ans; // result vector

        for (auto p : nodes) 
        { // iterate through the stored nodes
            vector<int> col; // column vector

            for (auto q : p.second) 
            { // iterate through nodes with same x position
                col.insert(col.end(), q.second.begin(), q.second.end()); // insert nodes in the column
            }

            ans.push_back(col); // push the column to the result
        }

        return ans; // return the vertical order traversal
    }
};
