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
    TreeNode* ans = new TreeNode();
    TreeNode* headans = ans;
    void preorder(TreeNode* root){
        if(!root){
            return;
        }
        ans->right = new TreeNode(root->val);
        ans->left = nullptr;
        ans = ans->right;
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        preorder(root);
        *root = *(headans->right);
    }
};