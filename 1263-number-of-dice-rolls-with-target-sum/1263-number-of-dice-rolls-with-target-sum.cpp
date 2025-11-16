class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[31][1001];
    int N, T;
    int solve(int i, int k, int cur){
        if (i==N && cur==T){
            return 1;
        }
        if (i>=N || cur>T){
            return 0;
        }
        if (dp[i][cur] != -1){
            return dp[i][cur];
        }
        int ans = 0;
        for (int o=1;o<=k;++o){
            ans += solve(i+1, k, cur+o)%MOD;
            ans %= MOD;
        }
        
        return dp[i][cur] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof dp);
        T = target;
        N = n;
        return solve(0, k, 0);
    }
};