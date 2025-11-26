class Solution {
public:
    static const int MOD = 1e9 + 7;
    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
    bool isTarget(int i, int j, vector<vector<int>>& grid) {
        return i == grid.size() - 1 && j == grid[0].size() - 1;
    }
    int solve(int i, int j, int sum, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp, int k) {
        if (isTarget(i, j, grid)) {
            if ((sum + grid[i][j]) % k == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if (!isSafe(i, j, grid)) {
            return 0;
        }
        if (dp[i][j][sum % k] != -1) {
            return dp[i][j][sum % k] % MOD;
        }
        return dp[i][j][sum % k] =
                   ((solve(i + 1, j, sum + grid[i][j], grid, dp, k) % MOD) +
                    (solve(i, j + 1, sum + grid[i][j], grid, dp, k) % MOD)) %
                   MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return solve(0, 0, 0, grid, dp, k);
    }
};