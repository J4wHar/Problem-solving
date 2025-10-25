class Solution {
public:
    static const int N = 2e3 + 5;
    vector<int> graph[N];
    int color[N];
    bool bfs(int parent){
        queue<int> q;
        q.push(parent);
        color[parent] = 1;
        while (!q.empty()){
            int p = q.front();
            q.pop();
            for (auto& x: graph[p]){
                if (!color[x]){
                    color[x] = color[p] == 1 ? 2 : 1;
                    q.push(x);
                }else if (color[x] == color[p]){
                    return false;
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for (auto& x: dislikes){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        memset(color, 0, sizeof color);
        for (int i=1;i<=n;++i){
            if (color[i]){
                continue;
            }
            if (!bfs(i)){
                return false;
            }
        }

        return true;
    }
};