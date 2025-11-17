class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> idxs;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                idxs.push_back(i);
            }
        }
        int sz = idxs.size();
        if (sz < 2) {
            return true;
        }
        for (int i = 1; i < sz; ++i) {
            if (idxs[i] - idxs[i - 1] <= k) {
                return false;
            }
        }
        return true;
    }
};