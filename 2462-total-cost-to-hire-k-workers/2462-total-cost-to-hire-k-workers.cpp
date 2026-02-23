class Solution {
public:
    static const int INF = 1e6;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if (candidates >= costs.size()) {
            sort(costs.begin(), costs.end());
            long long ans = 0;
            for (int i = 0; i < min(k, n); ++i) {
                ans += costs[i];
            }

            return ans;
        }
        int l = 0, r = n - 1;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<>> left, right;
        while (k) {
            while (left.size() < candidates && l <= r) {
                left.push(costs[l++]);
            }
            while (right.size() < candidates && l <= r) {
                right.push(costs[r--]);
            }
            int leftValue = left.empty() ? INF : left.top();
            int rightValue = right.empty() ? INF : right.top();
            if (leftValue <= rightValue) {
                ans += leftValue;
                left.pop();
            } else {
                ans += rightValue;
                right.pop();
            }
            k--;
        }

        return ans;
    }
};