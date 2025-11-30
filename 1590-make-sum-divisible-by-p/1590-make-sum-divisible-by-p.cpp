class Solution {
public:
    static const int N = 1e5 + 3;
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> idx;
        int pref[N];
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
            pref[i + 1] %= p;
        }
        int ans = 1e6;
        int target = pref[n];
        if (target == 0) {
            return 0;
        }
        for (int i = 0; i <= n; ++i) {
            int goal = (pref[i] - target + p) % p;
            if (idx[goal]) {
                ans = min(ans, i + 1 - idx[goal]);
            }
            idx[pref[i]] = i + 1;
        }

        return ans < n ? ans : -1;
    }
};