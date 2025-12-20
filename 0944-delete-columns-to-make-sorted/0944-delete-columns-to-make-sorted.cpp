class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int columnsSize = strs[0].size();
        int n = strs.size();
        int ans = 0;
        for (int column = 0; column < columnsSize; ++column) {
            bool toDelete = false;
            for (int i = 1; i < n; ++i) {
                if (strs[i][column] < strs[i - 1][column]) {
                    toDelete = true;
                    break;
                }
            }
            if (toDelete) {
                ++ans;
            }
        }

        return ans;
    }
};