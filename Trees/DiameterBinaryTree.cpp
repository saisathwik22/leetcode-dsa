// leetcode 543
// TC - O(n) 
// SC - O(1) - Auxillary Space
// SC - O(depth of Binary tree) - Recursion Stack Space
// amazon, cadince india, directi, makemytrip, microsoft, oracle, OYO, philips, salesforce, snapdeal, VMWare.
class Solution {
public:
    int diameter(TreeNode* root, int& ans) {
        if(!root) return 0;

        int left = diameter(root->left, ans);
        int right = diameter(root->right, ans);

        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int result = INT_MIN;

        diameter(root, result);

        return result;
    }
};
