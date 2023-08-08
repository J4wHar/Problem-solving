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
    priority_queue<int> minHeap;
    void dfs(TreeNode* root, int k){
        if(!root){
            return;
        }
        if(minHeap.size() < k){
            minHeap.push(root->val);
        }else{
            if(minHeap.top() > root->val){
                minHeap.pop();
                minHeap.push(root->val);
            }
        }
        dfs(root->right, k);
        dfs(root->left, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return minHeap.top();
    }
};