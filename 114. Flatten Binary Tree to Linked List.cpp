class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* currentNode = root;
        while (currentNode != nullptr) {
            if (currentNode->left != nullptr) {
                TreeNode* rightmostInLeftSubtree = currentNode->left;
                while (rightmostInLeftSubtree->right != nullptr) {
                    rightmostInLeftSubtree = rightmostInLeftSubtree->right;
                }
                rightmostInLeftSubtree->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = nullptr;
            }
            currentNode = currentNode->right;
        }
    }
};
