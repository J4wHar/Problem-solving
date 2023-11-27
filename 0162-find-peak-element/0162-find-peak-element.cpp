class Solution {
public:
    bool ok(int x, vector<int>& nums){
        if(x == 0){
            return nums[x] > nums[x+1];
        }
        if(x == nums.size() - 1){
            return nums[x] > nums[x-1];
        }
        return nums[x] > nums[x+1] && nums[x] > nums[x-1];
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        int l = 0;
        int r = n-1;
        while(l < r){
            int m = l+(r-l)/2;
            if(ok(m, nums)){
                return m;
            }
            if(nums[m+1] > nums[m-1]){
                l = m;
            }else{
                r = m;
            }
        }
        return 0;
    }
};