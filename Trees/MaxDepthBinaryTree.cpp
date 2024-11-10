// leetcode 104
// TC - O(n) SC - O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHT = maxDepth(root->left);
        int rightHT = maxDepth(root->right);

        return 1 + max(leftHT, rightHT); 
    }
};
