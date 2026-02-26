class Solution {
public:
    static const int N = 105;
    static const int INF = 1e7;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(N, INF);
        vector<pair<int, int>> graph[N];
        for (const auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) {
                continue;
            }

            for (auto [nextNode, weight] : graph[node]) {
                if (dist[nextNode] > d + weight) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};