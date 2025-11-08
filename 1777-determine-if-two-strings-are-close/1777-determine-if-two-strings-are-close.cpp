class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> occ1, occ2;
        for (auto& x : word1) {
            ++occ1[x];
        }
        for (auto& x : word2) {
            ++occ2[x];
        }
        for (auto& x : word1){
            if (!occ2[x]){
                return false;
            }
        }
        for (auto& x : word2){
            if (!occ1[x]){
                return false;
            }
        }
        unordered_map<int, int> countOcc1;
        for (auto& x : occ1) {
            ++countOcc1[x.second];
        }
        for (auto& x : occ2) {
            --countOcc1[x.second];
        }
        for (auto& x : countOcc1) {
            if (x.second) {
                return false;
            }
        }

        return true;
    }
};