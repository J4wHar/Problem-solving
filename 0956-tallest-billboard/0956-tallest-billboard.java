class Solution {
    private int memo[][] = new int[20][10000];
    private int solve(int i , int diff , int[] rods){
        if(i == rods.length){
            if(diff == 0){
                return 0;
            }else{
                return -100000;
            }
        }
        if(memo[i][diff+5000] != -1){
            return memo[i][diff+5000];
        }
        int l,r,n;
        l = rods[i] + solve(i+1 , diff+rods[i] , rods);
        r = solve(i+1 , diff-rods[i] , rods);
        n = solve(i+1 , diff , rods);
        return memo[i][diff+5000] = Math.max(Math.max(l,r),n);
    }
    public int tallestBillboard(int[] rods) {
        for(int i=0;i<rods.length;++i){
            for(int j=0;j<10000;++j){
                memo[i][j] = -1;
            }
        }
        int ans = solve(0,0,rods);
        return Math.max(ans , 0);
    }
}