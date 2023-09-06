class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;++i){
            if(mp.containsKey(nums[i])){
                if(i-mp.get(nums[i]) <= k){
                    return true;
                }else{
                    mp.put(nums[i], i);
                }
            }else{
                mp.put(nums[i], i);
            }
        }
        return false;
    }
}