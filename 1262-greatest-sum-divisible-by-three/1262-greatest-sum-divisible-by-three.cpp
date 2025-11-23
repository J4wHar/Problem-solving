class Solution {
public:
    static const int N = 4e4 + 3;
    int dp[N][3];
    int getValue(int i, int j, vector<int>& nums) {
        return dp[i][j] == 0 ? 0 : dp[i][j] + nums[i];
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] % 3 == 0) {
                dp[i][0] = dp[i - 1][0] + nums[i - 1];
                for (int j = 1; j < 3; ++j) {
                    dp[i][j] = getValue(i - 1, j, nums);
                }
            } else if (nums[i - 1] % 3 == 1) {
                dp[i][0] = max(dp[i - 1][0], getValue(i - 1, 2, nums));
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], getValue(i - 1, 1, nums));
            } else {
                dp[i][0] = max(dp[i - 1][0], getValue(i - 1, 1, nums));
                dp[i][1] = max(dp[i - 1][1], getValue(i - 1, 2, nums));
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
            }
        }

        return dp[n][0];
    }
};