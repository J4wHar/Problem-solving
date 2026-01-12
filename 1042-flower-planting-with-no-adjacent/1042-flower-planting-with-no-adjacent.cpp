class Solution {
public:
    static const int N = 1e4 + 3;
    vector<int> graph[N];
    vector<int> flowers = {1, 2, 3, 4};
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans = vector<int>(n, 0);
        for (auto& x : paths) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for (int p = 1; p <= n; ++p) {
            if (ans[p - 1]) {
                continue;
            }
            queue<int> q;
            q.push(p);
            int cur = 0;
            ans[p - 1] = 1;
            while (!q.empty()) {
                int parent = q.front();
                q.pop();
                for (auto& child : graph[parent]) {
                    if (ans[child - 1]) {
                        continue;
                    }
                    unordered_set<int> ss;
                    for (auto& x : graph[child]){
                        ss.insert(ans[x-1]);
                    }
                    while (ss.count(flowers[cur])){
                        ++cur;
                        cur %= 4;
                    }
                    ans[child - 1] = flowers[cur];
                    q.push(child);
                }
            }
        }

        return ans;
    }
};