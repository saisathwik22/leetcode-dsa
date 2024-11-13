// leetcode 235
// TC - O(Ht of Tree) SC - O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int currNode = root->val;
        if(currNode < p->val && currNode < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(currNode > p->val && currNode > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
