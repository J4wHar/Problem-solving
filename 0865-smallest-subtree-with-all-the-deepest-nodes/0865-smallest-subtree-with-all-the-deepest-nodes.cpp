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
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, TreeNode*> node;
    int maxLevel = 0;
    void countLevels(TreeNode* root, int lvl = 0) {
        if (!root) {
            return;
        }
        node[root->val] = root;
        maxLevel = max(maxLevel, lvl);
        mp[lvl].insert(root->val);
        countLevels(root->left, lvl + 1);
        countLevels(root->right, lvl + 1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        countLevels(root);
        if (mp[maxLevel].size() == 1) {
            return node[*mp[maxLevel].begin()];
        }
        int lvl = maxLevel - 1;
        auto children = mp[maxLevel];
        auto parents = mp[lvl];
        while (lvl > 0) {
            unordered_set<int> ancs;
            for (auto p : parents) {
                auto n = node[p];
                if (n->left && children.count(n->left->val)) {
                    ancs.insert(p);
                    continue;
                }
                if (n->right && children.count(n->right->val)) {
                    ancs.insert(p);
                }
            }
            --lvl;
            children = ancs;
            parents = mp[lvl];
            if (ancs.size() == 1) {
                break;
            }
        }

        return children.size() == 1 ? node[*children.begin()] : root;
    }
};