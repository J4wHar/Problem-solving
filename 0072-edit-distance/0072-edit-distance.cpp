class Solution {
public:
    int n, m;
    int memo[501][501];
    int solve(int i, int j, string& s1, string& s2){
        if(j == m && i == n){
            return 0;
        }
        if(i > n || j > m){
            return 1e7;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s1[i] == s2[j]){
            return memo[i][j] = solve(i+1, j+1, s1, s2);
        }
        return memo[i][j] = 1+min(solve(i+1, j+1, s1, s2), //replace
                                 min(solve(i+1, j, s1, s2), //delete
                                 solve(i, j+1, s1, s2))); //insert 
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memset(memo, -1, sizeof memo);
        return solve(0, 0, word1, word2);
    }
};