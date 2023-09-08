class Solution {
    private List<List<Integer>> pascal = new ArrayList<>();
    private int solve(int n, int k){
        if(n == 0){
            pascal.get(n).set(k, 1);
            return 1;
        }
        if(k == 0){
            pascal.get(n).set(k, 1);
            return 1;
        }
        if(n == k){
            pascal.get(n).set(k, 1);
            return 1;
        }
        if(pascal.get(n).get(k) != -1){
            return pascal.get(n).get(k);
        }
        int x = solve(n-1, k) + solve(n-1, k-1);
        pascal.get(n).set(k, x);
        return x;
    }
    public List<List<Integer>> generate(int numRows) {
        for(int i=0;i<numRows;++i){
            pascal.add(new ArrayList<>());
            for(int j=0;j<=i;++j){
                pascal.get(i).add(-1);
            }
        }
        for(int i=0;i<numRows;++i){
            for(int j=0;j<=i;++j){
                solve(i, j);
            }
        }
        return pascal;
    }
}