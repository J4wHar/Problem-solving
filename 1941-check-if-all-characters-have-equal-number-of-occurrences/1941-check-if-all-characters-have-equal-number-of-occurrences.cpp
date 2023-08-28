class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> occ;
        for(auto x: s){
            ++occ[x];
        }
        int cnt = -1;
        for(auto x: occ){
            if(cnt == -1){
                cnt = x.second;
            }else{
                if(cnt != x.second){
                    return false;
                }
            }
        }
        return true;
    }
};