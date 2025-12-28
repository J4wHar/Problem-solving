class Solution {
public:
    int binarySearchFirstNegativeIntIndex(vector<int>& v) {
        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (v[m] >= 0) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return v[l] < 0 ? l : l + 1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto& x : grid) {
            ans += x.size() - binarySearchFirstNegativeIntIndex(x);
        }

        return ans;
    }
};