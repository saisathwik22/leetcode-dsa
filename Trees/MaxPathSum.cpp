// leetcode 124
// Google, amazon, meta, flipkart
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);

        int ansAtBottom = l + r + root->val;
        int ansLeftOrRight = max(l, r) + root->val;
        int ansOnlyRoot = root->val;

        maxSum = max({maxSum, ansAtBottom, ansLeftOrRight, ansOnlyRoot});
        return max(ansLeftOrRight, ansOnlyRoot);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};
