/*
Using recursion to find maximum depth of binary tree.

For every node:
- Find depth of left subtree
- Find depth of right subtree
- Return 1 + maximum of both depths

TC: O(N)
SC: O(H)
*/
int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh,rh);
}