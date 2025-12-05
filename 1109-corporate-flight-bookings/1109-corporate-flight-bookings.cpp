class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<vector<int>> v;
        for (auto& booking : bookings) {
            v.push_back({booking[0], 0, booking[2]});
            v.push_back({booking[1], 1, booking[2]});
        }
        sort(v.begin(), v.end());
        int cur = 0;
        int sum = 0;
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (cur == v.size() || (cur == 0 && i < v[cur][0])) {
                ans.push_back(0);
                continue;
            }
            while (cur<v.size() && v[cur][0] <= i) {
                if (v[cur][0] == i && v[cur][1]) {
                    break;
                }
                v[cur][1] ? sum -= v[cur][2] : sum += v[cur][2];
                ++cur;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};