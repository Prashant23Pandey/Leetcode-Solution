class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
  
private:
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        if (!leftNode && !rightNode) {
            return true;
        }
        if (!leftNode || !rightNode) {
            return false;
        }
        return (leftNode->val == rightNode->val) &&
               isMirror(leftNode->left, rightNode->right) &&
               isMirror(leftNode->right, rightNode->left);
    }
};
