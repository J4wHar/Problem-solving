class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private void backtrack(int idx, int n, int k, List<Integer> temp){
        if(temp.size() == k){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=idx;i<=n;++i){
            temp.add(i);
            backtrack(i+1, n, k, temp);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> temp = new ArrayList<>();
        backtrack(1, n, k, temp);
        return ans;
    }
}