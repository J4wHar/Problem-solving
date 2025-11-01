class Solution {
public:
int m, n;
bool visited[200][200];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isSafe(int x, int y, vector<vector<int>>& heights){
    return x>=0 && x<m && y>=0 && y<n;
}
bool bfs(int i, int j, vector<vector<int>>& heights){
    queue<vector<int>> q;
    q.push({i, j});
    visited[i][j] = true;
    bool hasReachedPacific = false;
    bool hasReachedAtlantic = false;
    while (!q.empty()){
        vector<int> parent = q.front();
        q.pop();
        i = parent[0];
        j = parent[1];
        hasReachedPacific |= (i==0) || (j==0);
        hasReachedAtlantic |= i==m-1 || j==n-1;
        if (hasReachedPacific && hasReachedAtlantic){
            return true;
        }
        for (int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if (isSafe(x, y, heights) && !visited[x][y] && heights[x][y]<=heights[i][j]){
                q.push({x,y});
                visited[x][y] = true;
            }
        }
    }
    
    return false;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();
    vector<vector<int>> ans;
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            memset(visited, false, sizeof visited);
            if (bfs(i, j, heights)){
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}
};