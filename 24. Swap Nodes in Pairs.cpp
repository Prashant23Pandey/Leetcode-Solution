class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* remainingList = swapPairs(head->next->next);
        ListNode* newHead = head->next;
        newHead->next = head;
        head->next = remainingList;
        return newHead;
    }
};
