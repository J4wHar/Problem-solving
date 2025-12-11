class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> x;
        unordered_map<int, set<int>> y;
        for (auto& b : buildings) {
            x[b[0]].insert(b[1]);
            y[b[1]].insert(b[0]);
        }
        int ans = 0;
        for (auto& b : buildings) {
            bool cond1 = (x[b[0]].find(b[1]) != x[b[0]].end()) &&
                         (x[b[0]].find(b[1]) != --x[b[0]].end()) && 
                         (x[b[0]].find(b[1]) != x[b[0]].begin());
            bool cond2 = (y[b[1]].find(b[0]) != y[b[1]].end()) &&
                         (y[b[1]].find(b[0]) != --y[b[1]].end()) && 
                         (y[b[1]].find(b[0]) != y[b[1]].begin());

            ans += (cond1 && cond2);
        }

        return ans;
    }
};