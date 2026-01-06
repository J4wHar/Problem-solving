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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        unordered_map<int, int> levelSum;
        q.push({root, 1});
        while (!q.empty()) {
            auto parent = q.front();
            levelSum[parent.second] += parent.first->val;
            q.pop();
            if (parent.first->left) {
                q.push({parent.first->left, parent.second + 1});
            }
            if (parent.first->right) {
                q.push({parent.first->right, parent.second + 1});
            }
        }
        int levelValue = -1e9;
        int level;
        for (auto& x : levelSum) {
            if (x.second > levelValue) {
                levelValue = x.second;
                level = x.first;
            }
            if (x.second == levelValue) {
                level = min(level, x.first);
            }
        }

        return level;
    }
};