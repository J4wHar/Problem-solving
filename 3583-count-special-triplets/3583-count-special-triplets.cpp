class Solution {
public:
    static const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long int> cnt;
        unordered_map<int, long int> currentCnt;
        long int ans = 0;
        for (auto& x : nums) {
            ++cnt[x];
        }
        for (auto& x : nums) {
            int target = x << 1;
            --cnt[x];
            if (cnt[target] > 0 && currentCnt[target] > 0) {
                ans += ((cnt[target] * currentCnt[target]) % MOD);
                ans %= MOD;
            }
            ++currentCnt[x];
        }

        return (int)ans;
    }
};