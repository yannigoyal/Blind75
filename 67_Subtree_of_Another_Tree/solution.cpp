/*
Check if subRoot exists inside the main tree.

Approach:
- Traverse every node of the main tree
- For each node, check if both trees are identical
- isSameTree() compares:
  - node values
  - left subtree
  - right subtree

If any subtree matches completely, return true.

TC: O(n * m)
SC: O(h)

n = nodes in root
m = nodes in subRoot
h = height of tree (recursive stack)
*/
bool isSameTree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr && subRoot == nullptr) {
        return true;
    }
    if ((root == nullptr && subRoot != nullptr) ||
        (root != nullptr && subRoot == nullptr))
        return false;

    if (root->val != subRoot->val) {
        return false;
    }

    return isSameTree(root->left, subRoot->left) &&
            isSameTree(root->right, subRoot->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) {
        return false;
    }
    if (isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
}