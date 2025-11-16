class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping_t, mapping_s;
        int n = s.size();
        string attempt_t = "";
        string attempt_s = "";
        for (int i = 0; i < n; ++i) {
            mapping_s[s[i]] = t[i];
            mapping_t[t[i]] = s[i];
        }
        for (int i = 0; i < n; ++i) {
            attempt_t += mapping_s[s[i]];
            attempt_s += mapping_t[t[i]];
        }

        return attempt_t == t && attempt_s == s;
    }
};