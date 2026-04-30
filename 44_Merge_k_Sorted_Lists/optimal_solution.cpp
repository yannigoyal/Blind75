/*
Approach:
- We use a min-heap (priority queue) to efficiently get the smallest node
  among all the current heads of the k linked lists.
- First, push the head of each non-empty list into the heap.
- Then, repeatedly:
    1. Take the smallest node from the heap (top element).
    2. Attach it to the result list.
    3. If this node has a next node, push that next node into the heap.
- Continue this process until the heap becomes empty.
- A dummy node is used to simplify result list construction.

Why it works:
- At any time, the heap stores at most one node from each list,
  so the smallest element overall is always on top.

TC: O(N log k)   // N = total nodes, k = number of lists
SC: O(k)         // heap stores at most k nodes
*/
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)
        return nullptr;

    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                   greater<pair<int, ListNode*>>>
        pq;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr) {
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        ListNode* node = it.second;
        temp->next = node;
        temp = temp->next;

        if (node->next != nullptr) {
            pq.push({node->next->val, node->next});
        }
    }

    return dummy->next;
}
