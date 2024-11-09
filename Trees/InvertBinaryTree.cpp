// leetcode 226

class Solution {
public:
    void swap(TreeNode* curr) {
        if(!curr) return;
        swap(curr->left);
        swap(curr->right);
        TreeNode* temp;
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};
