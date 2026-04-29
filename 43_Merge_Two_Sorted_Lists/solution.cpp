/*
We use a dummy node to build the merged list easily.
Compare nodes of both lists one by one and attach the smaller value to the result.
Move the pointer of the chosen list forward.
After one list ends, attach the remaining part of the other list.

TC: O(n + m)
SC: O(1)
*/
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* result = dummy;
    if(list1 == nullptr) {
        return list2;
    }
    if(list2 == nullptr) {
        return list1;
    }
    while(list1!=nullptr && list2!=nullptr) {
        if(list1->val <= list2->val) {
            dummy->next = list1;
            list1 = list1->next;
        } else {
            dummy->next = list2;
            list2 = list2->next;
        }
        dummy = dummy->next;
    }
    if(list1!=nullptr) {
        dummy->next = list1;
    } else {
        dummy->next = list2;
    }
    return result->next;
}
