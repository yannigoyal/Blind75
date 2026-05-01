/*
Approach:
- First, count total nodes in the linked list.
- Find the position of node to delete from start: (count - n).
- If this position is 0, remove the head node.
- Otherwise, move to (count - n - 1)th node and update its next pointer.

TC: O(N)
SC: O(1)
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp = head;
    ListNode* curr = head;
    int count =0;
    int k=0;

    while(temp!=nullptr) {
        count++;
        temp = temp->next;
    }
    if(count - n == 0) {
        return head->next;
    }
    while(k!= count-n-1) {
        curr = curr->next;
        k++;
    }
    curr->next = curr->next->next;
    return head;
}
