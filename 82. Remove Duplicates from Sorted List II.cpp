class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* previous = dummyNode;
        ListNode* current = head;
        while (current != nullptr) {
            while (current->next != nullptr && current->next->val == current->val) {
                current = current->next;
            }
            if (previous->next == current) {
                previous = current;
            } else {
                previous->next = current->next;
            }
            current = current->next;
        }
        return dummyNode->next;
    }
};