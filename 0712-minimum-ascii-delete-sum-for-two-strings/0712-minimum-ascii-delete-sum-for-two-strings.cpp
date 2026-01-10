class Solution {
public:
    static const int N = 1e3 + 5;
    int dp[N][N];
    int solve(int i, int j, string& s1, string& s2) {
        if (i == s1.size() && j == s2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == s1.size()) {
            return dp[i][j] = (int)s2[j] + solve(i, j + 1, s1, s2);
        }
        if (j == s2.size()) {
            return dp[i][j] = (int)s1[i] + solve(i + 1, j, s1, s2);
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);
        }
        return dp[i][j] = min((int)s1[i] + solve(i + 1, j, s1, s2),
                              (int)s2[j] + solve(i, j + 1, s1, s2));
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, s1, s2);
    }
};