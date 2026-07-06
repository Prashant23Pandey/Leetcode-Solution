class Solution {
public:
    /**
     * Determines if two binary trees are identical.
     * Two binary trees are considered the same if they are structurally identical
     * and the nodes have the same values.
     *
     * @param p - Pointer to the root of the first binary tree
     * @param q - Pointer to the root of the second binary tree
     * @return true if both trees are identical, false otherwise
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};