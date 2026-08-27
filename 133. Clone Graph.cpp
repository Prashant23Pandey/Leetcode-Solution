class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> originalToClone;
        auto dfs = [&](this auto&& dfs, Node* currentNode) -> Node* {
            if (!currentNode) {
                return nullptr;
            }
            if (originalToClone.contains(currentNode)) {
                return originalToClone[currentNode];
            }
            Node* clonedNode = new Node(currentNode->val);
            originalToClone[currentNode] = clonedNode;
            for (auto& neighbor : currentNode->neighbors) {
                clonedNode->neighbors.push_back(dfs(neighbor));
            }
            return clonedNode;
        };
        return dfs(node);
    }
};
