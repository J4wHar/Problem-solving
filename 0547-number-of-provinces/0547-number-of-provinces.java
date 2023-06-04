class Solution {
    private boolean[] visited = new boolean[203];
    private void dfs(int parent , int[][] graph){
        visited[parent] = true;
        for(int child=0;child<graph.length;++child){
            if(graph[parent][child]==1 && !visited[child]){
                dfs(child , graph);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int ans = 0;
        int n = isConnected.length;
        for(int i=0;i<n;++i){
            visited[i] = false;
        }
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(i , isConnected);
                ++ans;
            }
        }
        return ans;
    }
}