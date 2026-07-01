class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* previousNode = nullptr;
        TreeNode* firstMisplacedNode = nullptr;
        TreeNode* secondMisplacedNode = nullptr;
        function<void(TreeNode*)> inorderTraversal = [&](TreeNode* currentNode) {
            if (!currentNode) {
                return;
            }
            inorderTraversal(currentNode->left);
            if (previousNode && previousNode->val > currentNode->val) {
                if (!firstMisplacedNode) {
                    firstMisplacedNode = previousNode;
                }
                secondMisplacedNode = currentNode;
            }
            previousNode = currentNode;
            inorderTraversal(currentNode->right);
        };
        inorderTraversal(root);
        swap(firstMisplacedNode->val, secondMisplacedNode->val);
    }
};