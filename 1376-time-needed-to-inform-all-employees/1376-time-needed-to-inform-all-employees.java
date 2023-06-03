class Solution {
    private List<List<Integer>> graph = new ArrayList<>();
    private int ans = 0;
    void dfs(int parent , int time , int[] informTime){
        for(int i=0;i<graph.get(parent).size();++i){
            dfs(graph.get(parent).get(i) , time+informTime[graph.get(parent).get(i)] , informTime);
        }
        ans = Math.max(ans , time);
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        for(int i=0;i<n;++i){
            graph.add(new ArrayList<>());
        }
        for(int i=0;i<n;++i){
            if(i != headID){
                graph.get(manager[i]).add(i);
            }
        }
        dfs(headID , informTime[headID] , informTime);
        return ans;
    }
}