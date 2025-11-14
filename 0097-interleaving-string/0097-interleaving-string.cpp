class Solution {
public:
    int dp[101][101];
    bool solve(int i, int j, string s1, string s2, string s3) {
        if (i == s1.size() && j == s2.size() && i + j == s3.size()) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s3[i + j] && s2[j] == s3[i + j] && i < s1.size() &&
            j < s2.size()) {
            return dp[i][j] = solve(i + 1, j, s1, s2, s3) ||
                              solve(i, j + 1, s1, s2, s3);
        }
        if (s1[i] == s3[i + j] && i < s1.size()) {
            return dp[i][j] = solve(i + 1, j, s1, s2, s3);
        }
        if ((s2[j] == s3[i + j]) && j < s2.size()) {
            return dp[i][j] = solve(i, j + 1, s1, s2, s3);
        }
        return dp[i][j] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        memset(dp, -1, sizeof dp);
        return solve(0, 0, s1, s2, s3);
    }
};