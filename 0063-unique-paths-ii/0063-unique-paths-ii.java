class Solution {
    private int n, m;
    private int[][] memo = new int[100][100];
    private boolean safe(int x, int y){
        return x<n && y<m;
    }
    private int solve(int i, int j, int[][] grid){
        if(i==n-1 && j==m-1){
            if(grid[i][j]==1){
                return 0;
            }
            return 1;
        }
        if(!safe(i, j) || grid[i][j]==1){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        return memo[i][j] = solve(i+1, j, grid) + solve(i, j+1, grid);
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        n = obstacleGrid.length;
        m = obstacleGrid[0].length;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                memo[i][j] = -1;
            }
        }
        return solve(0, 0, obstacleGrid);
    }
}