class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    const int INF = 1e6;
    int dist[101][101];
    bool visited[101][101];
    bool isExit(int i, int j, vector<vector<char>>& maze){
        return i==0 || i==maze.size()-1 || j==0 || j==maze[0].size()-1;
    }
    bool isSafe(int i, int j, vector<vector<char>>& maze){
        return i>=0 && i<maze.size() && j>=0 && j<maze[0].size();
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int x = entrance[0];
        int y = entrance[1];
        int ans = INF;
        q.push(make_pair(x, y));
        memset(dist, INF, sizeof dist);
        memset(visited, false, sizeof visited);
        dist[x][y] = 0;
        visited[x][y] = true;
        while (!q.empty()){
            pair<int, int> parent = q.front();
            q.pop();
            for (int k=0;k<4;++k){
                int child_x = parent.first + dx[k];
                int child_y = parent.second + dy[k];
                if (isSafe(child_x, child_y, maze)
                    && !visited[child_x][child_y]
                    && maze[child_x][child_y] != '+'){
                    q.push(make_pair(child_x, child_y));
                    dist[child_x][child_y] = 1 + dist[parent.first][parent.second];
                    visited[child_x][child_y] = true;
                    if (isExit(child_x, child_y, maze)){
                        ans = min(ans, dist[child_x][child_y]);
                    }
                }
            }
        }

        return ans == INF ? -1 : ans;
    }
};