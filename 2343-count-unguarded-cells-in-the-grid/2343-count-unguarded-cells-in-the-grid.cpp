class Solution {
public:
    // 0 empty 
    // 1 guard 
    // 2 wall
    // 3 flagged
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int maze[m][n];
        int ans = 0;
        memset(maze, 0, sizeof maze);
        for (auto& guard: guards){
            maze[guard[0]][guard[1]] = 1;
        }
        for (auto& wall: walls){
            maze[wall[0]][wall[1]] = 2;
        }
        bool hasEncountredGuard = false;
        for (int i=0;i<m;++i){
            for (int j=0;j<n;++j){
                if (maze[i][j] == 1){
                    hasEncountredGuard = true;
                    continue;
                }
                if (maze[i][j] == 2){
                    hasEncountredGuard = false;
                }
                if (hasEncountredGuard && !maze[i][j]){
                    maze[i][j] = 3;
                    ++ans;
                }
            }
            hasEncountredGuard = false;
        }
        hasEncountredGuard = false;
        for (int i=0;i<m;++i){
            for (int j=n-1;j>=0;--j){
                if (maze[i][j] == 1){
                    hasEncountredGuard = true;
                    continue;
                }
                if (maze[i][j] == 2){
                    hasEncountredGuard = false;
                    continue;
                }
                if (hasEncountredGuard && !maze[i][j]){
                    maze[i][j] = 3;
                    ++ans;
                }
            }
            hasEncountredGuard = false;
        }
        hasEncountredGuard = false;
        for (int j=0;j<n;++j){
            for (int i=0;i<m;++i){
                if (maze[i][j] == 1){
                    hasEncountredGuard = true;
                    continue;
                }
                if (maze[i][j] == 2){
                    hasEncountredGuard = false;
                }
                if (hasEncountredGuard && !maze[i][j]){
                    maze[i][j] = 3;
                    ++ans;
                }
            }
            hasEncountredGuard = false;
        }

        hasEncountredGuard = false;
        for (int j=0;j<n;++j){
            for (int i=m-1;i>=0;--i){
                if (maze[i][j] == 1){
                    hasEncountredGuard = true;
                    continue;
                }
                if (maze[i][j] == 2){
                    hasEncountredGuard = false;
                }
                if (hasEncountredGuard && !maze[i][j]){
                    maze[i][j] = 3;
                    ++ans;
                }
            }
            hasEncountredGuard = false;
        }

        return m*n - guards.size() - walls.size() - ans;
    }
};