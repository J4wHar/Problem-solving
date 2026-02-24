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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    int eval(string& cur){
        int n = cur.size();
        int ans = 0;
        for (int i=0;i<n;++i){
            if (cur[i] == '1'){
                ans += (1<<(n-i-1));
            }
        }

        return ans;
    }
    int sumRootToLeaf(TreeNode* root, string cur = "") {
        if (!root){
            return 0;
        }
        cur += to_string(root->val);
        if (isLeaf(root)){
            return eval(cur);
        }
        return sumRootToLeaf(root->left, cur) + sumRootToLeaf(root->right, cur);
    }
};