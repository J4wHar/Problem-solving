class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;++i){
            mp.put(nums[i], i);
        }
        int[] ans = new int[2];
        for(int i=0;i<n;++i){
            if(mp.containsKey(target-nums[i]) && mp.get(target-nums[i]) != i){
                ans[0] = i;
                ans[1] = mp.get(target-nums[i]);
                return ans;
            }
        }
        return null;
    }
}