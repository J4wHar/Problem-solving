class Solution {
public:
    static const int N = 1e3 + 6;
    int dp[N][N];
    vector<int> getMaxAndMin(vector<int>& nums) {
        int maxNums = nums[0];
        int minNums = nums[0];
        for (auto& x : nums) {
            maxNums = max(maxNums, x);
            minNums = min(minNums, x);
        }

        return {maxNums, minNums};
    }
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int p = nums1[i] * nums2[j];
        if (p > 0) {
            return dp[i][j] = max(p + solve(i + 1, j + 1, nums1, nums2),
                                  max(solve(i + 1, j, nums1, nums2),
                                      solve(i, j + 1, nums1, nums2)));
        }
        return dp[i][j] = max(solve(i + 1, j, nums1, nums2),
                              solve(i, j + 1, nums1, nums2));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1 = getMaxAndMin(nums1);
        vector<int> v2 = getMaxAndMin(nums2);
        if (v1[1] > 0 && v2[0] < 0) {
            return v1[1] * v2[0];
        }
        if (v1[0] < 0 && v2[1] > 0) {
            return v1[0] * v2[1];
        }
        memset(dp, -1, sizeof dp);
        return solve(0, 0, nums1, nums2);
    }
};