class Solution {
public:
    char mat[1000][1000];
    int n, m;
    void solve(int i, int j, int idx, string& s){
        if(idx == m){
            return;
        }
        mat[i][j] = s[idx];
        bool vertical = j%(n-1) == 0;
        if(vertical){
            if(i == n-1){
                solve(i-1, j+1, idx+1, s);
            }
            solve(i+1, j, idx+1, s);
        }else{
            solve(i-1, j+1, idx+1, s);
        }
    }
    string convert(string s, int numRows) {
        n = numRows;
        if(n == 1){
            return s;
        }
        m = s.size();
        memset(mat, ' ', sizeof mat);
        string ans = "";
        solve(0, 0, 0, s);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j] != ' '){
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};