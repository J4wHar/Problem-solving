class Solution {
public:
    static const int N = 502;
    const int INF = 1e8;
    int dp[N][N][3][2];
    int n, m;
    bool isSafe(int i, int j, int n, int m) { return i < n && j < m; }
    int solve(int i, int j, int neutralized, bool neutralize,
              vector<vector<int>>& coins) {
        if (i == n - 1 && j == m - 1) {
            return neutralize ? 0 : coins[i][j];
        }
        if (!isSafe(i, j, n, m)) {
            return -INF;
        }
        if (dp[i][j][neutralized][neutralize] != -INF) {
            return dp[i][j][neutralized][neutralize];
        }
        if (neutralized == 2) {
            dp[i][j][neutralized][neutralize] =
                max(solve(i + 1, j, neutralized, false, coins),
                    solve(i, j + 1, neutralized, false, coins));
            return dp[i][j][neutralized][neutralize] +=
                   neutralize ? 0 : coins[i][j];
        }

        dp[i][j][neutralized][neutralize] =
            max(max(solve(i + 1, j, neutralized, false, coins),
                    solve(i, j + 1, neutralized, false, coins)),
                max(solve(i + 1, j, neutralized + 1, true, coins),
                    solve(i, j + 1, neutralized + 1, true, coins)));

        return dp[i][j][neutralized][neutralize] +=
               neutralize ? 0 : coins[i][j];
    }
    int maximumAmount(vector<vector<int>>& coins) {
        fill(&dp[0][0][0][0], &dp[0][0][0][0] + N * N * 3 * 2, -INF);
        n = coins.size();
        m = coins[0].size();
        return max(solve(0, 0, 1, true, coins), solve(0, 0, 0, false, coins));
    }
};