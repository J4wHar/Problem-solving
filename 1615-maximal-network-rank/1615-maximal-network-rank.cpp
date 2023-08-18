class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        bool edge[n][n];
        memset(edge, 0, sizeof edge);
        unordered_map<int, int> occ;
        for(auto road: roads){
            edge[road[0]][road[1]] = 1;
            edge[road[1]][road[0]] = 1;
            ++occ[road[0]];
            ++occ[road[1]];
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                ans = max(ans, occ[i]+occ[j]-edge[i][j]);
            }
        }
        return ans;
    }
};