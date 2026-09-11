class Solution {
public:
    /**
     * Sorts a linked list using insertion sort algorithm
     * @param head - The head of the linked list to be sorted
     * @return The head of the sorted linked list
     */
    ListNode* insertionSortList(ListNode* head) {
        // Handle edge cases: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
      
        // Create a dummy node to simplify insertion at the beginning
        // Initialize dummy with a minimal value and point to nullptr initially
        ListNode* dummy = new ListNode(INT_MIN);
      
        // Current node being processed from the original list
        ListNode* current = head;
      
        // Process each node in the original list
        while (current != nullptr) {
            // Store the next node to process before modifying pointers
            ListNode* next_node = current->next;
          
            // Find the correct position to insert current node in sorted portion
            ListNode* insert_position = dummy;
            while (insert_position->next != nullptr && 
                   insert_position->next->val < current->val) {
                insert_position = insert_position->next;
            }
          
            // Insert current node at the found position
            current->next = insert_position->next;
            insert_position->next = current;
          
            // Move to the next node in the original list
            current = next_node;
        }
      
        // Store the head of sorted list and clean up dummy node
        ListNode* sorted_head = dummy->next;
        delete dummy;
      
        // Return the sorted list
        return sorted_head;
    }
};
