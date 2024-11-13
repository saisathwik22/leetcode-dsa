// leetcode 1448
// Microsoft ****
// TC - O(n) SC - O(1)
class Solution {
public:
    int search(TreeNode* curr, int max) {
        if(!curr) return 0;
        int cnt = 0;
        if(curr->val >= max) {
            cnt++;
            max = curr->val;
        }
        cnt += search(curr->left, max);
        cnt += search(curr->right, max);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int gudNodes = 1;
        gudNodes += search(root->left, root->val);
        gudNodes += search(root->right, root->val);
        return gudNodes;
    }
};
