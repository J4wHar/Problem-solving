class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        Map<Integer, Integer> occ = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;++i){
            if(occ.containsKey(nums[i])){
                occ.put(nums[i], occ.get(nums[i])+1);
            }else{
                occ.put(nums[i], 1);
            }
        }
        occ.forEach((x, y) -> {
            if(y > (n/3)){
                ans.add(x);
            }
        });
        return ans;
    }
}