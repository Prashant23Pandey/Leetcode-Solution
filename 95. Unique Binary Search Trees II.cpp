class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> generateBSTsInRange = [&](int start, int end) {
            if (start > end) {
                return vector<TreeNode*>{nullptr};
            }
            vector<TreeNode*> allPossibleTrees;
            for (int rootValue = start; rootValue <= end; ++rootValue) {
                vector<TreeNode*> leftSubtrees = generateBSTsInRange(start, rootValue - 1);
                vector<TreeNode*> rightSubtrees = generateBSTsInRange(rootValue + 1, end);
                for (TreeNode* leftSubtree : leftSubtrees) {
                    for (TreeNode* rightSubtree : rightSubtrees) {
                        TreeNode* currentTree = new TreeNode(rootValue, leftSubtree, rightSubtree);
                        allPossibleTrees.push_back(currentTree);
                    }
                }
            }
            return allPossibleTrees;
        };
        return generateBSTsInRange(1, n);
    }
};