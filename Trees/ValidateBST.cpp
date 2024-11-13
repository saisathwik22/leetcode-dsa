// leetcode 98
// Approach - DFS
// TC - O(n) SC - O(1)
class Solution {
public:
    bool checkValidBST(TreeNode* root, long minVal, long maxVal) {
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) {
            return false;
        }
        return checkValidBST(root->left, minVal, root->val) && checkValidBST(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return checkValidBST(root, LONG_MIN, LONG_MAX);
    }
};
