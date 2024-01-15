class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> nbLosses;
        set<int> teams;
        vector<vector<int>> ans;
        vector<int> noLosses;
        vector<int> oneLoss;
        for(auto &x: matches){
            ++nbLosses[x[1]];
            teams.insert(x[0]);
            teams.insert(x[1]);
        }
        for(auto &x: teams){
            if(nbLosses[x] == 0){
                noLosses.push_back(x);
            }
            if(nbLosses[x] == 1){
                oneLoss.push_back(x);
            }
        }
        ans = {noLosses, oneLoss};
        return ans;
    }
};