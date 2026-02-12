class Solution {
public:
    int longestBalanced(string& s) {
        int n = s.size();
        unordered_map<char, vector<int>> occ;
        unordered_set<char> disctinctChars;
        for (auto& x : s) {
            disctinctChars.insert(x);
        }
        int ans = 1;
        for (char x : disctinctChars) {
            occ[x].push_back(0);
            for (int c = 0; c < n; ++c) {
                if (s[c] == x) {
                    occ[x].push_back(occ[x].back() + 1);
                } else {
                    occ[x].push_back(occ[x].back());
                }
            }
        }
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                int target = -1;
                bool valid = true;
                for (int x : disctinctChars) {
                    int cnt = occ[x][r + 1] - occ[x][l];
                    if (cnt == 0){
                        continue;
                    }
                    if (target == -1){
                        target = cnt;
                        continue;
                    }
                    if (target != cnt){
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};