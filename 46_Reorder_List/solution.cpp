/*
Approach:
1. Use slow & fast pointers to find middle of list.
2. Split list into two halves.
3. Reverse the second half.
4. Merge both halves alternately (first → second → first...).

Key Idea:
Rearrange links (not values) to achieve L0 → Ln → L1 → Ln-1...

TC: O(n)
SC: O(1)
*/
void reorderList(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast = head;
    ListNode* first = head;

    if(head->next == nullptr) return;
    while(fast->next!=nullptr && fast->next->next!=nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second= slow->next;
    slow->next = nullptr;

    second = reverseList(second);
    while(second!=nullptr) {
        ListNode* temp1=first->next;
        ListNode* temp2 =second->next;
        first->next=second;

        second->next=temp1;

        first=temp1;
        second=temp2;
    }

}
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
