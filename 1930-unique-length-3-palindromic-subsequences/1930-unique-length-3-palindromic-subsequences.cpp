class Solution {
public:
    bool isPalindrome(string s) { return s[0] == s[2]; }
    unordered_set<string> prepareAns() {
        unordered_set<string> ss;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    string cur = "";
                    char x = 'a' + i;
                    char y = 'a' + j;
                    char z = 'a' + k;
                    cur += x;
                    cur += y;
                    cur += z;
                    if (isPalindrome(cur)) {
                        ss.insert(cur);
                    }
                }
            }
        }

        return ss;
    }
    int countPalindromicSubsequence(string s) {
        unordered_set<string> ss = prepareAns();
        int ans = 0;
        for (auto& target : ss) {
            int cur = 0;
            for (auto& c : s) {
                if (c == target[cur]) {
                    cur++;
                }
                if (cur == 3) {
                    ++ans;
                    break;
                }
            }
        }

        return ans;
    }
};