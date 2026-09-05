/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * Detects if a linked list has a cycle and returns the node where the cycle begins.
     * Uses Floyd's Cycle Detection Algorithm (Tortoise and Hare).
     * 
     * @param head The head of the linked list
     * @return The node where the cycle begins, or nullptr if no cycle exists
     */
    ListNode* detectCycle(ListNode* head) {
        // Initialize two pointers for cycle detection
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
      
        // Phase 1: Detect if a cycle exists using two pointers moving at different speeds
        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            // Move slow pointer one step forward
            slowPointer = slowPointer->next;
            // Move fast pointer two steps forward
            fastPointer = fastPointer->next->next;
          
            // If pointers meet, a cycle exists
            if (slowPointer == fastPointer) {
                // Phase 2: Find the start of the cycle
                // Mathematical proof: Distance from head to cycle start equals
                // distance from meeting point to cycle start
                ListNode* startPointer = head;
              
                // Move both pointers one step at a time until they meet
                while (startPointer != slowPointer) {
                    startPointer = startPointer->next;
                    slowPointer = slowPointer->next;
                }
              
                // The meeting point is the start of the cycle
                return startPointer;
            }
        }
      
        // No cycle detected
        return nullptr;
    }
};
