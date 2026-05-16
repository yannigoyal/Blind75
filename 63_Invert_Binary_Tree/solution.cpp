/*
    Recursively invert the binary tree.
    First invert left and right subtrees,
    then swap the left and right child of current node.

    TC: O(N)
    SC: O(H)
*/
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) {
        return nullptr;
    }
    invertTree(root->left);
    invertTree(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}