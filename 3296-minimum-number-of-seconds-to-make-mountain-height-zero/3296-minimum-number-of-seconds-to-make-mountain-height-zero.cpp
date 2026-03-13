#define ll long long
class Solution {
public:
    struct compare {
        bool operator()(const vector<ll>& x, const vector<ll>& y) const {
            return x[0] + (x[1] + 1) * x[2] > y[0] + (y[1] + 1) * y[2];
        }
    };
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<vector<ll>, vector<vector<ll>>, compare> pq;
        for (int worker : workerTimes) {
            pq.push({0, 0, worker});
        }
        long long ans = 0;
        while (mountainHeight--) {
            vector<ll> minWorker = pq.top();
            pq.pop();
            minWorker[1]++;
            minWorker[0] += (minWorker[1] * minWorker[2]);
            ans = max(minWorker[0], ans);
            pq.push(minWorker);
        }

        return ans;
    }
};