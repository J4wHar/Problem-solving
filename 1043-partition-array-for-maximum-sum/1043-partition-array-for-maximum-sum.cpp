class Solution {
public:
    int memo[500];
    int n;
    int solve(int i, int k, vector<int>& arr){
        if(i>=n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int maxx = 0;
        for(int idx=i;idx<i+k;++idx){
            if(idx<n){
                maxx = max(arr[idx], maxx);
                memo[i] = max(memo[i], maxx*(idx-i+1)+solve(idx+1, k, arr));
            }
        }
        return memo[i];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(memo, -1, sizeof memo);
        return solve(0, k, arr);
    }
};