/*
Using DFS, calculate max path sum from left and right subtrees.
Ignore negative paths using max(0, path).
At every node, update global answer with:
left + right + root->val
Return the best single path to parent.

TC: O(N)
SC: O(H)
*/
class Solution {
public:
    int maxi = INT_MIN;

    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        maxi = max(maxi, left + right + root->val);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};