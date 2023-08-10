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
    void generateTree(TreeNode* ans, int l, int r, vector<int>& nums){
        int m = l + (r-l)/2;
        if(r<l){
            return;
        }
        ans->val = nums[m];
        if(l<=m-1){
            ans->left = new TreeNode();
        }
        if(m+1<=r){
            ans->right = new TreeNode();
        }
        generateTree(ans->left, l, m-1, nums);
        generateTree(ans->right, m+1, r, nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = new TreeNode();
        TreeNode* head = ans;
        int n = nums.size();
        generateTree(ans, 0, n-1, nums);
        return head;
    }
};