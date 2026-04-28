/*
 * Detect cycle using Floyd's Tortoise & Hare algorithm.
 * slow moves 1 step, fast moves 2 steps.
 * If cycle exists, they will meet inside the loop.
 * If no cycle, fast hits NULL and we return false.
 *
 * TC: O(n)  SC: O(1)
 */
bool hasCycle(ListNode *head) {
    ListNode* slow=head;
    if(head == NULL || head->next == NULL)
        return false;
    ListNode* fast = head->next; 
    while(fast != NULL && fast->next!=NULL ) {
        if(fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
