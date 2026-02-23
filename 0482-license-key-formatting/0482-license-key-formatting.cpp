class Solution {
public:
    int calculateFirstGroupLenth(string& s, int k) {
        int cnt = 0;
        for (char c : s) {
            cnt += (c != '-');
        }

        return cnt % k;
    }
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        int firstGpLength = calculateFirstGroupLenth(s, k);
        string ans = "";
        if (firstGpLength == 0) {
            int cur = 0;
            for (char c : s) {
                if (c == '-') {
                    continue;
                }
                if (cur < k) {
                    ++cur;
                } else {
                    ans += '-';
                    cur = 1;
                }
                ans += (isalpha(c) ? toupper(c) : c);
            }

            return ans;
        }
        int cur = 0;
        int i;
        for (i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '-') {
                continue;
            }
            if (cur < firstGpLength) {
                ++cur;
                ans += (isalpha(c) ? toupper(c) : c);
            } else {
                ans += '-';
                cur = 0;
                break;
            }
        }
        
        for (int idx = i; idx < n; ++idx) {
            char c = s[idx];
            if (c == '-') {
                continue;
            }
            if (cur < k) {
                ++cur;
            } else {
                ans += '-';
                cur = 1;
            }
            ans += (isalpha(c) ? toupper(c) : c);
        }

        return ans;
    }
};