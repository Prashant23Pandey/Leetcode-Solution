class Solution {
public:
    int sumNumbers(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int currentSum) -> int {
            if (!node) {
                return 0;
            }
            currentSum = currentSum * 10 + node->val;
            if (!node->left && !node->right) {
                return currentSum;
            }
            int leftSum = dfs(node->left, currentSum);
            int rightSum = dfs(node->right, currentSum);
            return leftSum + rightSum;
        };
        return dfs(root, 0);
    }
};
