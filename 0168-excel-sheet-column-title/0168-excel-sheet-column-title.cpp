class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n){
            if(n%26){
                ans += (char) (n%26) + 'A' - 1;
            }else{
                ans += 'Z';
                n -= 26;
            }
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};