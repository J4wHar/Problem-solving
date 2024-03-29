class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int difference = 1e5;
        int ans = 1e5;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;++i){
            int l = i+1;
            int r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(sum-target) < difference){
                    difference = abs(sum - target);
                    ans = sum;
                }
                if(sum == target){
                    return sum;
                }else if(sum < target){
                    ++l;
                }else{
                    --r;
                }
            }
        }
        return ans;
    }
};