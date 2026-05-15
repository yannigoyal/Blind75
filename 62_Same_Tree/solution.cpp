/*
Compare both trees using recursion.

1. If both nodes are NULL -> same tree
2. If one node is NULL -> different tree
3. Check current values and recursively compare
   left subtree and right subtree

TC: O(n)
SC: O(h)
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) {
        return true;
    }

    if(p == nullptr || q == nullptr) {
        return false;
    }

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}