class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int n = matrix.size();
        int cnt = 0;
        int minn = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt += (matrix[i][j] < 0);
                minn = min(minn, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }

        return cnt % 2 == 0 ? ans : ans - 2*minn;
    }
};