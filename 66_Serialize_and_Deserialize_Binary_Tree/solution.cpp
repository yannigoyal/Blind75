/*
Serialize & Deserialize Binary Tree using BFS (Level Order Traversal)

Serialize:
- Traverse the tree level by level using queue
- Store each node value in string
- Store "N" for NULL nodes so tree structure is preserved
- Example:
  Tree:       1
            /   \
           2     3

  Serialized String:
  "1,2,3,N,N,N,N,"

Deserialize:
- Split the string using ','
- Create root node from first value
- Use queue to reconnect left and right children level by level
- If value is "N", child will be NULL

Why "N" is needed?
- Without NULL markers, original tree structure cannot be rebuilt correctly

TC: O(n)
SC: O(n)
*/
string serialize(TreeNode* root) {
    if (!root)
        return "N";

    queue<TreeNode*> q;
    q.push(root);

    string ans = "";

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
            ans += "N,";
            continue;
        }

        ans += to_string(node->val) + ",";

        q.push(node->left);
        q.push(node->right);
    }

    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "N")
        return NULL;

    vector<string> vals;
    string temp = "";

    for (char c : data) {
        if (c == ',') {
            vals.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }

    TreeNode* root = new TreeNode(stoi(vals[0]));

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (vals[i] != "N") {
            node->left = new TreeNode(stoi(vals[i]));
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != "N") {
            node->right = new TreeNode(stoi(vals[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}