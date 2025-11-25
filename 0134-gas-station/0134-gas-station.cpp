class Solution {
public:
    static const int N = 1e5 + 3;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diff[N];
        diff[0] = 0;
        int ans, minn = 1e9;
        for (int i = 0; i < n; ++i) {
            diff[i + 1] = diff[i] + (gas[i] - cost[i]);
            if (minn > diff[i+1]){
                minn = diff[i+1];
                ans = (i+1)%n;
            }
        }
        
        if (diff[n] < 0){
            return -1;
        }

        return ans;
    }
};