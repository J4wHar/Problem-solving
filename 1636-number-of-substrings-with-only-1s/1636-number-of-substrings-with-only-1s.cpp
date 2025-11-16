class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        int ans = 0;
        long long cnt = 0;
        for (auto& x : s) {
            if (x == '0') {
                if (cnt > 0) {
                    long long cur = (cnt * (cnt + 1)) / 2;
                    ans += (cur % MOD) % MOD;
                    cnt = 0;
                }
            } else {
                ++cnt;
            }
        }
        long long cur = (cnt * (cnt + 1)) / 2;
        ans += (cur % MOD) % MOD;
        cnt = 0;

        return ans;
    }
};