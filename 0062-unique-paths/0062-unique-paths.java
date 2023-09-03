class Solution {
    private int memo[][] = new int[100][100];
    private int solve(int m, int n){
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(memo[m][n] != -1){
            return memo[m][n];
        }
        return memo[m][n] = solve(m-1, n) + solve(m, n-1);
    }
    public int uniquePaths(int m, int n) {
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                memo[i][j] = -1;
            }
        }
        return solve(m-1, n-1);
    }
}