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
     * Performs postorder traversal of a binary tree
     * @param root - The root node of the binary tree
     * @return A vector containing node values in postorder sequence (left, right, root)
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;  // Store the traversal result
      
        // Define recursive function for depth-first search
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            // Base case: if node is null, return
            if (!node) {
                return;
            }
          
            // Postorder traversal: left -> right -> root
            dfs(node->left);   // Traverse left subtree
            dfs(node->right);  // Traverse right subtree
            result.push_back(node->val);  // Process current node
        };
      
        // Start the traversal from root
        dfs(root);
      
        return result;
    }
};
