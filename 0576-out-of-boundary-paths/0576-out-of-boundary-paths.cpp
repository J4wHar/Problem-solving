class Solution {
public:
    const int MOD = 7 + 1e9;
    int memo[51][51][51];
    bool out(int i, int j, int n, int m){
        return i<0 || i>=n || j<0 || j>=m;
    }
    int solve(int i, int j, int maxMove, int n, int m){
        if(out(i, j, n, m)){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }
        if(memo[i][j][maxMove] != -1){
            return memo[i][j][maxMove];
        }
        memo[i][j][maxMove] = solve(i, j+1, maxMove-1, n, m)%MOD;
        memo[i][j][maxMove] += (solve(i, j-1, maxMove-1, n, m)%MOD);
        memo[i][j][maxMove] %= MOD;
        memo[i][j][maxMove] += (solve(i+1, j, maxMove-1, n, m)%MOD);
        memo[i][j][maxMove] %= MOD;
        memo[i][j][maxMove] += (solve(i-1, j, maxMove-1, n, m)%MOD);
        return memo[i][j][maxMove]%MOD;
            
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof memo);
        return solve(startRow, startColumn, maxMove, m , n);
    }
};