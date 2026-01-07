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
    long long ans = 0;
    long long sum = 0;
    static const int MOD = 1e9 + 7;
    long long max(long long x, long long y) { return x > y ? x : y; }
    int solve(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right) {
            return root->val;
        }

        return root->val += solve(root->left) + solve(root->right);
    }
    void calculateAns(TreeNode* root) {
        if (!root) {
            return;
        }

        ans = max(ans, root->val * (sum - root->val));
        calculateAns(root->left);
        calculateAns(root->right);
    }
    int maxProduct(TreeNode* root) {
        sum = solve(root);
        calculateAns(root);
        return (int)(ans % MOD);
    }
};