/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /**
     * Sorts a linked list using merge sort algorithm
     * Time Complexity: O(n log n)
     * Space Complexity: O(log n) for recursion stack
     * 
     * @param head The head of the linked list to be sorted
     * @return The head of the sorted linked list
     */
    ListNode* sortList(ListNode* head) {
        // Base case: empty list or single node
        if (!head || !head->next) {
            return head;
        }
      
        // Find the middle of the list using two-pointer technique
        // slow moves one step, fast moves two steps
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;  // Start fast at head->next to handle even-length lists correctly
      
        while (fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
      
        // Split the list into two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = slowPtr->next;
        slowPtr->next = nullptr;  // Disconnect the two halves
      
        // Recursively sort both halves
        firstHalf = sortList(firstHalf);
        secondHalf = sortList(secondHalf);
      
        // Merge the two sorted halves
        ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify merging
        ListNode* currentTail = dummyHead;
      
        // Merge nodes from both lists in sorted order
        while (firstHalf && secondHalf) {
            if (firstHalf->val <= secondHalf->val) {
                currentTail->next = firstHalf;
                firstHalf = firstHalf->next;
            } else {
                currentTail->next = secondHalf;
                secondHalf = secondHalf->next;
            }
            currentTail = currentTail->next;
        }
      
        // Append remaining nodes from either list
        currentTail->next = firstHalf ? firstHalf : secondHalf;
      
        // Return the merged sorted list (skip dummy head)
        ListNode* sortedHead = dummyHead->next;
        delete dummyHead;  // Clean up dummy node
        return sortedHead;
    }
};
