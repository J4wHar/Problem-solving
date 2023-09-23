class Solution {
public:
    bool isPref(string& s, string& t){
        int n = s.size();
        int m = t.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(s[i] == t[j]){
                ++j;
            }
            ++i;
        }
        return j == m;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int dp[n];
        int ans = 0;
        for(int i=0;i<n;++i){
            dp[i] = 1;
        }
        sort(words.begin(), words.end(), [](string s1, string s2){
            return s1.size() < s2.size();
        });
        for(int i=n-1;i>=0;--i){
            for(int j=i-1;j>=0;--j){
                if(j != i){
                    if(words[i].size() == words[j].size()+1 && isPref(words[i], words[j])){
                        dp[j] = max(dp[j], 1+dp[i]);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};