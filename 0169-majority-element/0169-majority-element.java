class Solution {
    public int majorityElement(int[] nums) {
        int cnt = 1;
        int n = nums.length;
        Arrays.sort(nums);
        for(int i=1;i<n;++i){
            if(nums[i-1] == nums[i]){
                ++cnt;
                if(cnt > n/2){
                    return nums[i-1];
                }
            }else{
                cnt = 1;
            }
        }
        return nums[0];
    }
}