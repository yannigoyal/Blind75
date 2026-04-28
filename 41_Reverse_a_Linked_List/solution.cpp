/*
Approach:
We reverse the linked list using three pointers: prev, curr, and next.

- curr starts at head, prev starts as NULL.
- For each node:
  1. Store next node (next = curr->next) so we don’t lose the list.
  2. Reverse the link (curr->next = prev).
  3. Move prev to current node (prev = curr).
  4. Move curr to next node (curr = next).

- Continue until curr becomes NULL.
- At the end, prev will be pointing to the new head of the reversed list.

TC: O(n)
SC: O(1)
*/
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(curr!=nullptr) {
        next = curr->next; //save dont lose the chain
        curr->next = prev; // flip - reverse the pointer
        prev = curr; //move prev forward
        curr = next; // move curr forward
    }
    return prev;
}
