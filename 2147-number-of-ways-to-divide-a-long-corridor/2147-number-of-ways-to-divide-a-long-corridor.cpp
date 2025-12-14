class Solution {
public:
    static const int MOD = 7 + 1e9;
    int numberOfWays(string corridor) {
        long long ans = 1;
        int curChairs = 0;
        int curPlants = 0;
        int cntChairs = 0;
        for (auto& x : corridor) {
            cntChairs += (x == 'S');
        }
        if (cntChairs % 2 == 1 || cntChairs == 0) {
            return 0;
        }
        for (auto& x : corridor) {
            if (curChairs == 2) {
                if (x == 'S') {
                    ans *= ((curPlants + 1) % MOD);
                    ans %= MOD;
                    curPlants = 0;
                    curChairs = 1;
                } else {
                    ++curPlants;
                }
            } else {
                curChairs += (x == 'S');
            }
        }

        return ans;
    }
};