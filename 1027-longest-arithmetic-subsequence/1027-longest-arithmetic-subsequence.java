class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][1001];
        for(int i=0;i<n;++i){
            for(int j=0;j<1001;++j){
                dp[i][j] = 1;
            }
        }
        int ans = 1;
        int diff;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                diff = nums[i]-nums[j]+500;
                dp[i][diff] = Math.max(dp[i][diff] , 1+dp[j][diff]);
                ans = Math.max(ans , dp[i][diff]);
            }
        }
        return ans;
    }
}