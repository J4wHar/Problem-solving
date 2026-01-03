class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int N = 5e3 + 5;
    static const int P = 13;
    vector<string> patterns = {"121", "123", "131", "132", "212", "213",
                               "231", "232", "312", "313", "321", "323"};
    vector<int> getEligiblePatterns(string pattern) {
        vector<int> ans;
        for (int i = 0; i < 12; ++i) {
            string cur = patterns[i];
            if (cur[0] != pattern[0] && cur[1] != pattern[1] &&
                cur[2] != pattern[2]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    int numOfWays(int n) {
        int dp[N][P];
        unordered_map<string, vector<int>> memo;
        for (int j = 0; j < 12; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 12; ++j) {
                dp[i][j] = 0;
                string currentPattern = patterns[j];
                if (memo[currentPattern].size() == 0) {
                    memo[currentPattern] = getEligiblePatterns(currentPattern);
                }
                for (auto& x : memo[currentPattern]) {
                    dp[i][j] += (dp[i - 1][x] % MOD);
                    dp[i][j] %= MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < 12; ++j) {
            ans += dp[n - 1][j];
            ans %= MOD;
        }

        return ans;
    }
};