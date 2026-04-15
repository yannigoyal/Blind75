/*
Clone Graph (DFS + HashMap)

- Use DFS to traverse the graph.
- Create a clone node for each original node.
- Store mapping: original → clone (to handle cycles & reuse).
- For each neighbor, recursively clone and connect it.

TC: O(N)
SC: O(N)
*/

unordered_map<Node*, Node*> mp;
Node* dfs(Node* node) {
    if (node == NULL)
        return NULL;

    if (mp.find(node) != mp.end()) {
        return mp[node];
    }
    Node* clone_node = new Node(node->val);
    mp[node] = clone_node;
    for (auto it : node->neighbors) {
        clone_node->neighbors.push_back(dfs(it));
    }
    return clone_node;
}
Node* cloneGraph(Node* node) {
    if (node == NULL)
        return NULL;

    return dfs(node);
}
