class Solution {
public:
    int min(int x, int y){
        if(x < y){
            return x;
        }
        return y;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = 200;
        for(int i=0;i<n;++i){
            m = min(m, strs[i].size());
        }
        string ans = "";
        for(int j=0;j<m;++j){
            set<int> s;
            for(int i=0;i<n;++i){
                s.insert(strs[i][j]);
            }
            if(s.size() == 1){
                ans += strs[0][j];
            }else{
                break;
            }
        }
        return ans;
    }
};