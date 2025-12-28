class Solution {
public:
    static const int N = 1e6;
    int dp[N][3];
    int bs(vector<vector<int>>& events, int l) {
        int r = events.size() - 1;
        int target = events[l - 1][1];
        while (l < r) {
            int m = l + (r - l) / 2;
            if (events[m][0] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l < events.size() && events[l][0] > target ? l : events.size();
    }
    int solve(int i, int used, vector<vector<int>>& events) {
        if (i >= events.size() || used == 2) {
            return 0;
        }

        if (dp[i][used] != -1) {
            return dp[i][used];
        }

        int idx = bs(events, i + 1);

        return dp[i][used] = max(solve(i + 1, used, events),
                                 events[i][2] + solve(idx, used + 1, events));
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp, -1, sizeof dp);
        sort(events.begin(), events.end());
        return solve(0, 0, events);
    }
};