/*
Approach:
- Use two pointers (slow & fast) with a dummy node before head.
- Move fast pointer (n+1) steps ahead to create a gap of n nodes.
- Move both pointers together until fast reaches null.
- Slow will be at the previous node of the one to delete.
- Update slow->next to remove the target node.

TC: O(N)
SC: O(1)
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    for(int i = 0 ; i<=n;i++) {
        fast = fast->next;
    }

    while(fast!=nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}
