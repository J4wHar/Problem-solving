class Solution {
    
    private List<List<Integer>> ans = new ArrayList<>();
    private void backtrack(List<Integer> temp, int[] nums, boolean[] visited){
        if(temp.size() == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0;i<nums.length;++i){
            if(!visited[i]){
                temp.add(nums[i]);
                visited[i] = true;
                backtrack(temp, nums, visited);
                temp.remove(temp.size()-1);
                visited[i] = false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        int n = nums.length;
        boolean[] visited = new boolean[n];
        for(int i=0;i<n;++i){
            visited[i] = false;
        }
        backtrack(temp, nums, visited);
        return ans;
    }
}