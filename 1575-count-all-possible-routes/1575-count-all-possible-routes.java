class Solution {
    private int[][] memo = new int[100][201];
    private int MOD = 7 + 1000000000;
    private int solve(int i , int fuel , int finish , int[] locations){
        if(fuel < 0){
            return 0;
        }
        if(fuel == 0){
            if(i == finish){
                return 1;
            }
            return 0;
        }
        if(memo[i][fuel] != -1){
            return memo[i][fuel];
        }
        int ans = 0;
        if(i == finish){
            ++ans;
        }
        for(int x=0;x<locations.length;++x){
            if(i != x){
                ans = (ans%MOD) + solve(x , fuel-Math.abs(locations[x]-locations[i]),finish,locations);
                ans %= MOD;
            }
        }
        return memo[i][fuel] = ans;
    }
    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        for(int i=0;i<locations.length;++i){
            for(int j=0;j<=fuel;++j){
                memo[i][j] = -1;
            }
        }
        return solve(start,fuel,finish,locations);
    }
}