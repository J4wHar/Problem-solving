class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0;
        int loss = 1e6;
        int cntY = 0;
        int curCntN = 0;
        int curCntY = 0;
        int n = customers.size();
        for (auto& x : customers) {
            cntY += (x == 'Y');
        }
        for (int i = 0; i < n; ++i) {
            char x = customers[i];
            int curLoss = curCntN + (cntY - curCntY);
            if (curLoss < loss) {
                ans = i;
                loss = curLoss;
            }
            curCntN += (x == 'N');
            curCntY += (x == 'Y');
        }
        int curLoss = curCntN + (cntY - curCntY);
        if (curLoss < loss) {
            ans = n;
            loss = curLoss;
        }

        return ans;
    }
};