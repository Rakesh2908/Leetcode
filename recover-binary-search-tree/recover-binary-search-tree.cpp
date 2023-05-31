class Solution {
public:
    TreeNode* firstElement = nullptr;
    TreeNode* secondElement = nullptr;
    TreeNode* prevElement = new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root) 
    {
        traverse(root);
        swap(firstElement->val,secondElement->val);
    }

private:
    void traverse(TreeNode* root) 
    {
        if (root == nullptr)
            return;
            
        traverse(root->left);
        
        if (firstElement == nullptr && prevElement->val > root->val) 
        {
            firstElement = prevElement;
        }

        if (firstElement != nullptr && prevElement->val > root->val) 
        {
            secondElement = root;
        } 

        prevElement = root;

        traverse(root->right);
    }
};