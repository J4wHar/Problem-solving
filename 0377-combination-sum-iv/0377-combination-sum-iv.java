class Solution {
    private int[] memo = new int[1001];
    private int solve(int target, int[] nums){
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        if(memo[target] != -1){
            return memo[target];
        }
        memo[target] = 0;
        for(int i=0;i<nums.length;++i){
            if(target-nums[i] >= 0){
                memo[target] += solve(target-nums[i], nums);
            }
        }
        return memo[target];
    }
    public int combinationSum4(int[] nums, int target) {
        for(int i=0;i<=target;++i){
            memo[i] = -1;
        }
        return solve(target, nums);
    }
}