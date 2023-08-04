class Solution {
public:
    bool bs(int l, int r, vector<string>& wordDict, string s){
        int m = l+(r-l)/2;
        if(r<l){
            return false;
        }
        if(s == wordDict[m]){
            return true;
        }
        if(wordDict[m] < s){
            return bs(m+1, r, wordDict, s);
        }
        return bs(l, m-1, wordDict, s);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        bool dp[n+1];
        dp[n] = true;
        string str = "";
        for(int i=n-1;i>=0;--i){
            dp[i] = false;
            for(int j=0;j<m;++j){
                str = wordDict[j];
                if(i+str.size()<=n && s.substr(i, str.size())==str){
                    dp[i] = dp[i+str.size()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};