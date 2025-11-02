/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;
    void solve(TreeNode* root, string cur="1"){
        if (!root){
            return;
        }
        if (!root->left && !root-> right){
            cur += "->" + to_string(root->val);
            ans.push_back(cur);
            return;
        }
        cur += "->" + to_string(root->val);
        solve(root->left, cur);
        solve(root->right, cur);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root->left && !root-> right){
            ans.push_back(to_string(root->val));
            return ans;
        }
        string init = to_string(root->val);
        solve(root->left, init);
        solve(root->right, init);
        return ans;
    }
};