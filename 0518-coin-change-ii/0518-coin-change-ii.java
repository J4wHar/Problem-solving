class Solution {
    private int[][] memo = new int[300][5001];
    private int n;
    private int solve(int i, int amount, int[] coins){
        if(amount == 0){
            return 1;
        }
        if(i==n || amount<0){
            return 0;
        }
        if(memo[i][amount] != -1){
            return memo[i][amount];
        }
        return memo[i][amount] = solve(i, amount-coins[i], coins) + solve(i+1, amount, coins);
    }
    public int change(int amount, int[] coins) {
        n = coins.length;
        for(int i=0;i<n;++i){
            for(int j=0;j<=amount;++j){
                memo[i][j] = -1;
            }
        }
        return solve(0, amount, coins);
    }
}