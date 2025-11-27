class Solution {
public:
    static const int N = 2e5 + 3;
    long long max(long long x, long long y) {
        if (x >= y) {
            return x;
        }
        return y;
    }
    long long min(long long x, long long y) {
        if (x <= y) {
            return x;
        }
        return y;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long pref[N], minPref[N];
        pref[0] = 0;
        minPref[0] = 0;
        unordered_map<int, long long> minValue;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = nums[i] + pref[i];
        }
        long long ans = -1e15;
        for (int i = 0; i <= n; ++i) {
            if (!minValue.count(i % k)) {
                minValue[i % k] = pref[i];
            } else {
                ans = max(ans, pref[i] - minValue[i % k]);
                minValue[i % k] = min(minValue[i % k], pref[i]);
            }
        }

        return ans;
    }
};