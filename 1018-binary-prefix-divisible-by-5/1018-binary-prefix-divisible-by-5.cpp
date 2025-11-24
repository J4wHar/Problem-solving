class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur = 0;
        vector<bool> ans;
        for (auto& x : nums) {
            cur = (cur << 1) + x;
            cur %= 5;
            ans.push_back(cur ? false : true);
        }

        return ans;
    }
};