class Solution {
    public int[] productExceptSelf(int[] nums) {
        int cnt0 = 0;
        int n = nums.length;
        int[] ans = new int[n];
        int prod = 1;
        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                ++cnt0;
            }else{
                prod *= nums[i];    
            }            
        }
        if(cnt0 == 0){
            for(int i=0;i<n;++i){
                ans[i] = prod/nums[i];
            }
        }else if (cnt0 == 1){
            for(int i=0;i<n;++i){
                if(nums[i] == 0){
                    ans[i] = prod;
                }else{
                    ans[i] = 0;
                }
            }
        }else{
            for(int i=0;i<n;++i){
                ans[i] = 0;
            }
        }
        return ans;
    }
}