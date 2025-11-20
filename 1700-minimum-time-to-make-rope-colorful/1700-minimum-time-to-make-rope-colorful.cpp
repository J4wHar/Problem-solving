class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        priority_queue<int> pq;
        int n = colors.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                if (pq.empty()) {
                    pq.push(-neededTime[i - 1]);
                }
                pq.push(-neededTime[i]);
            } else {
                while (pq.size() > 1) {
                    ans -= pq.top();
                    pq.pop();
                }
                pq = priority_queue<int>();
            }
        }
        while (pq.size() > 1) {
            ans -= pq.top();
            pq.pop();
        }

        return ans;
    }
};