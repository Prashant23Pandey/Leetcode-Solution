class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummyHead = new Node(0);
        Node* currentNewNode = dummyHead;
        unordered_map<Node*, Node*> originalToCopy;
        for (Node* currentOriginal = head; currentOriginal != nullptr; currentOriginal = currentOriginal->next) {
            Node* copiedNode = new Node(currentOriginal->val);
            currentNewNode->next = copiedNode;
            currentNewNode = copiedNode;
            originalToCopy[currentOriginal] = copiedNode;
        }
        for (Node* currentOriginal = head; currentOriginal != nullptr; currentOriginal = currentOriginal->next) {
            // If original node has a random pointer, set the corresponding random pointer in the copy
            if (currentOriginal->random != nullptr) {
                originalToCopy[currentOriginal]->random = originalToCopy[currentOriginal->random];
            } else {
                originalToCopy[currentOriginal]->random = nullptr;
            }
        }
      
        // Return the head of the copied list (skip dummy node)
        return dummyHead->next;
    }
};
