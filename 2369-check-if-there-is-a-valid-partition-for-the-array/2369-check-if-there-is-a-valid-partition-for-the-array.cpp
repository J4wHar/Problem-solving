class Solution {
public:
    unordered_map<int,bool> memo;
    int n;
    bool solve(int i, vector<int>& nums){
        if(i == n){
            return true;
        }
        if(memo.count(i)){
            return memo[i];
        }
        bool ans = false;
        if(i<n-1 && nums[i]==nums[i+1]){
            ans |= solve(i+2, nums);
        }
        if(i<n-2 && ((nums[i]==nums[i+1] && nums[i+1]==nums[i+2]) || (nums[i]+1==nums[i+1] && nums[i+1]==nums[i+2]-1))){
            ans |= solve(i+3, nums);
        }
        return memo[i] = ans;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        return solve(0, nums);
    }
};