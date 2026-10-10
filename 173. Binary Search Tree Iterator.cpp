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
class BSTIterator {
private:
    std::vector<int> values;      // Stores all BST values in sorted order
    int currentIndex;              // Current position in the values vector
  
public:
    /**
     * Constructor: Initialize the iterator with the root of BST
     * Performs inorder traversal to populate values in sorted order
     * @param root: The root node of the binary search tree
     */
    BSTIterator(TreeNode* root) {
        currentIndex = 0;
        performInorderTraversal(root);
    }
  
    /**
     * Returns the next smallest number in the BST
     * @return: The value at current position and advances the iterator
     */
    int next() {
        return values[currentIndex++];
    }
  
    /**
     * Checks if there are more elements to iterate
     * @return: true if there are more elements, false otherwise
     */
    bool hasNext() {
        return currentIndex < values.size();
    }
  
private:
    /**
     * Helper function to perform inorder traversal of BST
     * Populates the values vector with node values in sorted order
     * @param node: Current node being processed
     */
    void performInorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            // Traverse left subtree
            performInorderTraversal(node->left);
          
            // Process current node
            values.push_back(node->val);
          
            // Traverse right subtree
            performInorderTraversal(node->right);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
