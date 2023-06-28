class Solution {
public:
    int sum = 0;
    int memo[200][20001];
    int n;
    int solve(int i , int s , vector<int>& nums){
        if(s == sum>>1){
            return 0;
        }
        if(i == n){
            return 1e9;
        }
        if(memo[i][s] != -1){
            return memo[i][s];
        }
        return memo[i][s] = min(solve(i+1,s+nums[i],nums),solve(i+1,s,nums));
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        memset(memo , -1 , sizeof memo);
        for(int i=0;i<n;++i){
            sum += nums[i];
        }
        if(sum&1){
            return false;
        }
        return solve(0,0,nums) == 0;        
    }
};