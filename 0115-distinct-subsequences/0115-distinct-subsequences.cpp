class Solution {
public:
    int memo[1005][1005];
    int n,m;
    int solve(string& s , string& t , int i , int j){
        if(j == m){
            return 1;
        }
        if(i == n){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s[i] == t[j]){
            return memo[i][j] = solve(s,t,i+1,j+1) + solve(s,t,i+1,j);
        }
        return memo[i][j] = solve(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        memset(memo , -1 , sizeof memo);
        n = s.size();
        m = t.size();
        return solve(s , t , 0 , 0);
    }
};