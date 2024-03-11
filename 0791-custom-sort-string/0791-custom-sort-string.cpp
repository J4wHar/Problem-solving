class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> occ;
        string ans = "";
        for(auto &x: s){
            ++occ[x];
        }
        for(auto &x: order){
            while(occ[x]--){
                ans += x;
            }
        }
        for(auto &x: occ){
            while(occ[x.first] > 0){
                ans += x.first;
                --occ[x.first];
            }
        }
        return ans;
    }
};