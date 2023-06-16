class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt0 = 0;
        int prod = 1;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                ++cnt0;
            }else{
                prod *= nums[i];
            }
        }
        if (cnt0 == 1){
            for(int i=0;i<n;++i){
                if(nums[i] == 0){
                    ans[i] = prod;
                }else{
                    ans[i] = 0;
                }
            }
        }else if (cnt0 == 0){
            for(int i=0;i<n;++i){
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};