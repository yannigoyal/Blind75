/*
Approach:
- We merge k sorted linked lists one by one using mergeTwoLists
- Start with the first list as head
- Then iteratively merge it with each next list
- mergeTwoLists compares nodes and builds a sorted merged list

Why it works:
- Each merge step maintains sorted order
- Final result is fully merged sorted list

TC: O(N * k)   // N = total nodes, k = number of lists
SC: O(1)       // no extra space, only pointers used
*/
class Solution {
public:
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)   
            return nullptr;
        ListNode* head = lists[0];

        for(int i= 1;i<lists.size();i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};

