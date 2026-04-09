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
    int sumNumbers(TreeNode* root, int cur = 0) {
        if (!root) {
            return 0;
        }
        int x = cur * 10 + root->val;
        if (!root->left && !root->right) {
            return x;
        }
        if (!root->left) {
            return sumNumbers(root->right, x);
        }
        if (!root->right) {
            return sumNumbers(root->left, x);
        }
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
    }
};