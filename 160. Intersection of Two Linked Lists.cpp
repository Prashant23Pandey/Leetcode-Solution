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
     * Find the intersection node of two linked lists.
     * 
     * Algorithm: Two-pointer technique
     * - Both pointers traverse their respective lists and then switch to the other list
     * - If there's an intersection, they'll meet at the intersection node
     * - If there's no intersection, they'll both reach NULL at the same time
     * 
     * Time Complexity: O(m + n) where m and n are the lengths of the two lists
     * Space Complexity: O(1)
     * 
     * @param headA: Head of the first linked list
     * @param headB: Head of the second linked list
     * @return: The intersection node if exists, otherwise NULL
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // Initialize two pointers to traverse both lists
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;
      
        // Continue until both pointers meet (either at intersection or NULL)
        while (pointerA != pointerB) {
            // If pointerA reaches the end of list A, redirect it to the head of list B
            // Otherwise, move to the next node in the current list
            pointerA = (pointerA != nullptr) ? pointerA->next : headB;
          
            // If pointerB reaches the end of list B, redirect it to the head of list A
            // Otherwise, move to the next node in the current list
            pointerB = (pointerB != nullptr) ? pointerB->next : headA;
        }
      
        // Return the meeting point (intersection node or NULL if no intersection)
        return pointerA;
    }
};
