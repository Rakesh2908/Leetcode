class Solution 
{
public:
    TreeNode* firstElement = nullptr;
    TreeNode* secondElement = nullptr;
    TreeNode* prevElement = nullptr;

    void recoverTree(TreeNode* root) 
    {
        findSwappedElements(root);
        swapValues(firstElement, secondElement);
    }

private:
    void findSwappedElements(TreeNode* root) 
    {
        if (root == nullptr)
            return;

        findSwappedElements(root->left);

        if (prevElement != nullptr && prevElement->val >= root->val) 
        {
            if (firstElement == nullptr) 
            {
                firstElement = prevElement;
            }
            secondElement = root;
        }

        prevElement = root;

        findSwappedElements(root->right);
    }

    void swapValues(TreeNode* node1, TreeNode* node2) 
    {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
