class Solution {
public:
    static const int N = 2e2 + 3;
    int mat[N][N];
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (i == 0){
                    mat[i][j] = matrix[i][j] - '0';
                    continue;
                }
                if (matrix[i][j] == '1'){
                    mat[i][j] = mat[i-1][j] + 1;
                } else {
                    mat[i][j] = 0;
                }
            }
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                int minn = mat[i][j];
                for (int l=j;l<m;++l){
                    minn = min(minn, mat[i][l]);
                    ans = max(ans, minn*(l-j+1));
                }
            }
        }

        return ans;
    }
};