class Solution {
public:
    double memo[25][25][101];
    bool safe(int x, int y, int n){
        return x>=0 && x<n && y>=0 && y<n;
    }
    double solve(int i, int j, int n, int k){
        if(!safe(i, j, n)){
            return 0;
        }
        if(!k){
            return 1.0;
        }
        if(memo[i][j][k] != -1.0){
            return memo[i][j][k];
        }
        return memo[i][j][k] = (solve(i-2, j+1, n, k-1) + solve(i-1, j+2, n, k-1)
            + solve(i+1, j+2, n, k-1) + solve(i+2, j+1, n, k-1)
            + solve(i+1, j-2, n, k-1) + solve(i+2, j-1, n, k-1)
            + solve(i-1, j-2, n, k-1) + solve(i-2, j-1, n, k-1))/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int z=0;z<=k;++z){
                    memo[i][j][z] = -1.0;
                }
            }
        }
        return solve(row, column, n, k);
    }
};