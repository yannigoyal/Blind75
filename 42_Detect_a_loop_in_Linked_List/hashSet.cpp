/*
 * Detect cycle using HashSet of node addresses.
 * Store each visited node's pointer in the set.
 * If we see the same address again, cycle exists.
 * If head->next hits NULL, no cycle found.
 *
 * TC: O(n)  SC: O(n)
*/
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;

    if(head == NULL) {
        return false;
    }
    while(head->next != NULL) {
        if(visited.count(head->next)) {
            return true;
        } else {
            visited.insert(head->next);
            head = head->next;
        }
    }
    return false;
}
