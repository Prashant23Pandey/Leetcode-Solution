class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* previousNode = nullptr;
        function<bool(TreeNode*)> inOrderValidate = [&](TreeNode* currentNode) -> bool {
            if (!currentNode) {
                return true;
            }
            if (!inOrderValidate(currentNode->left)) {
                return false;
            }
            if (previousNode && previousNode->val >= currentNode->val) {
                return false;
            }
            previousNode = currentNode;
            return inOrderValidate(currentNode->right);
        };
        return inOrderValidate(root);
    }
};