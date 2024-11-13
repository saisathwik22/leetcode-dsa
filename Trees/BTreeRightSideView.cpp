// leetcode 199
// Accolite Amazon Flipkart Knowlarity makeMyTrip OlaCabs OpenSolutions OYO PayTM Qualcomm Samsung Snapdeal Twitter
// Approach 1 - DFS
// TC - O(n)
class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& ans) {
        if(!root) {
            return;
        }
        if(ans.size() < level) {
            ans.push_back(root->val);
        }
        preOrder(root->right, level + 1, ans);
        preOrder(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> ans;

        preOrder(root, 1, ans);
        return ans;
    }
};
// Approach 2 - Level Order Traversal - BFS
// TC - O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> que;
        vector<int> ans;
        que.push(root);
        while(!que.empty()) {
            int n = que.size();
            TreeNode* rightNode = NULL;
            while(n--) {
                rightNode = que.front();
                que.pop();
                if(rightNode->left) {
                    que.push(rightNode->left);
                }
                if(rightNode->right) {
                    que.push(rightNode->right);
                }
            }
            ans.push_back(rightNode->val);
        }
        return ans;
    }
};
