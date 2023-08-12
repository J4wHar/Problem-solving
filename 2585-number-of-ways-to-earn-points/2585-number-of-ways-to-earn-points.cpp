class Solution {
public:
    int memo[50][1001];
    int n;
    int MOD = 7 + 1e9;
    int solve(int i, int target, vector<vector<int>>& types){
        if(target == 0){
            return 1;
        }
        if(target<0 || i==n){
            return 0;
        }
        if(memo[i][target] != -1){
            return memo[i][target];
        }
        memo[i][target] = 0;
        for(int x=0;x<=types[i][0];++x){
            memo[i][target] += (solve(i+1, target-(x*types[i][1]), types))%MOD;
            memo[i][target] %= MOD;
        }
        return memo[i][target] % MOD;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        memset(memo, -1, sizeof memo);
        return solve(0, target, types);
    }
};