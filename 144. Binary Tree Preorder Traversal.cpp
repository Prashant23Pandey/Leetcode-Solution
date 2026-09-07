/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * Performs preorder traversal of a binary tree
     * @param root - The root node of the binary tree
     * @return A vector containing node values in preorder sequence
     */
    vector<int> preorderTraversal(TreeNode* root) {
        // Vector to store the traversal result
        vector<int> result;
      
        // Lambda function for recursive depth-first search
        // Captures result vector by reference to modify it
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            // Base case: if node is null, return
            if (!node) {
                return;
            }
          
            // Preorder: process current node first
            result.push_back(node->val);
          
            // Recursively traverse left subtree
            dfs(node->left);
          
            // Recursively traverse right subtree
            dfs(node->right);
        };
      
        // Start the traversal from root
        dfs(root);
      
        return result;
    }
};
