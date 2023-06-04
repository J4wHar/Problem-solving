class Solution {
    public int removeElement(int[] nums, int val) {
        List<Integer> a = new ArrayList<>();
        int n = nums.length;
        for(int i=0;i<n;++i){
            if(nums[i] != val){
                a.add(nums[i]);
            }
        }
        int k = a.size();
        for(int i=0;i<k;++i){
            nums[i] = a.get(i);
        }
        return k;
    }
}