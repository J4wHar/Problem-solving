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
    unordered_map<int, int> occ;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        ++occ[root->val];
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        int max_occ = 0;
        for(auto &x: occ){
            max_occ = max(max_occ, x.second);
        }
        for(auto &x: occ){
            if(x.second == max_occ){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};