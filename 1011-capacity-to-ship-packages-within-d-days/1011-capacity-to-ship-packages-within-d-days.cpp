class Solution {
public:
    bool isValid(int capacity, vector<int>& weights, int days) {
        int currentCapacity = 0;
        int ans = 0;
        for (auto& w : weights) {
            if (w > capacity) {
                return false;
            }
            currentCapacity += w;
            if (currentCapacity > capacity) {
                ++ans;
                currentCapacity = w;
            }
        }
        if (currentCapacity) {
            ++ans;
        }

        return ans <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int r = 1e8;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isValid(m, weights, days)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};