class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private void backtrack(int idx, int n, int target, int sum, int[] candidates, List<Integer> temp){
        if(sum == target){
            ans.add(new ArrayList(temp));
            return;
        }
        if(sum > target){
            return;
        }
        for(int i=idx;i<n;++i){
            temp.add(candidates[i]);
            sum += candidates[i];
            backtrack(i, n, target, sum, candidates, temp);
            temp.remove(temp.size()-1);
            sum -= candidates[i];
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> temp = new ArrayList<>();
        int sum = 0;
        backtrack(0, candidates.length, target, sum, candidates, temp);
        return ans;
    }
}