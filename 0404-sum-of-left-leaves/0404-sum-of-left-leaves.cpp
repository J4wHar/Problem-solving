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
    bool isLeftLeaf(TreeNode* root, bool isLeft){
        return !root->left && !root->right && isLeft;
    }
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (!root){
            return 0;
        }
        if (isLeftLeaf(root, isLeft)){
            return root->val;
        }
        
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};