class Solution {
public:
    const int INF = 1e9;
    unordered_map<int, int> ones;
    unordered_map<int, int> zeros;
    int N;
    int dp[601][101][101];
    int solve(int i, int m, int n, vector<string>& strs) {
        if (m < 0 || n < 0) {
            return -INF;
        }
        if (i == N) {
            return 0;
        }
        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }
        return dp[i][m][n] =
                   max(1 + solve(i + 1, m - zeros[i], n - ones[i], strs),
                       solve(i + 1, m, n, strs));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        N = strs.size();
        for (int i=0;i<N;++i) {
            for (auto& c : strs[i]) {
                ones[i] += c == '1';
                zeros[i] += c == '0';
            }
        }
        memset(dp, -1, sizeof dp);

        return max(solve(0, m, n, strs), 0);
    }
};