class Solution {
public:
    bool isValid(int i, string& s){
        if (s[i-1] == '0'){
            return false;
        }
        if(s[i-1] == '1'){
            return true;
        }
        if (s[i-1] == '2'){
            return s[i] < '7';
        }
        return false;
    }
    int numDecodings(string s) {
        if (s[0] == '0'){
            return 0;
        }
        int n = s.size();
        int dp[n];
        for (int i=0;i<n;++i){
            if (i == 0){
                dp[i] = 1;
            }else{
                if (s[i] == '0'){
                    if (s[i-1] > '2' || s[i-1] == '0'){
                        return 0;
                    }
                    if (i-2 >=0){
                        dp[i] = dp[i-2];
                    }else{
                        dp[i] = 1;
                    }
                }else{
                    dp[i] = isValid(i, s) ? dp[max(0, i-2)]+dp[i-1] : dp[i-1];
                }
            }
        }

        return dp[n-1];
    }
};