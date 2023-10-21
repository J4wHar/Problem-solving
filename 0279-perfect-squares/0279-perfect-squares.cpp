class Solution {
public:
    int perfectSquares[100];
    int memo[10001];
    int solve(int n){
        if(n < 0){
            return 1e7;
        }
        if(n == 0){
            return 0;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        memo[n] = 1e7;
        for(int i=0;i<100;++i){
            if(n-perfectSquares[i] >= 0){
                memo[n] = min(memo[n], 1+solve(n-perfectSquares[i]));
            }
        }
        return memo[n];
    }
    int numSquares(int n) {
        for(int i=1;i<=100;++i){
            perfectSquares[i-1] = i*i;
        }
        memset(memo, -1, sizeof memo);
        return solve(n);
    }
};