class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> occ;
        string ans = "";
        for (auto& x : s){
            ++occ[x];
        }
        for (auto& x : order){
            while (occ[x]){
                ans += x;
                --occ[x];
            }
        }
        for (auto& x : occ){
            while (x.second){
                ans += x.first;
                x.second--;
            }
        }
        
        return ans;
    }
};