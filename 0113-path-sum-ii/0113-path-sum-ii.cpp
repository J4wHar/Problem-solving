/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int targetSum, vector<int> cur) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                cur.push_back(root->val);
                ans.push_back(cur);
            }
            return;
        }
        cur.push_back(root->val);
        solve(root->left, targetSum - root->val, cur);
        solve(root->right, targetSum - root->val, cur);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        solve(root, targetSum, cur);
        return ans;
    }
};