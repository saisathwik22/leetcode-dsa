// leetcode 102
// // BFS
// TC - O(n) SC - O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left != NULL) {
                    q.push(currNode->left);
                }
                if(currNode->right != NULL) {
                    q.push(currNode->right);
                }
                level.push_back(currNode->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
