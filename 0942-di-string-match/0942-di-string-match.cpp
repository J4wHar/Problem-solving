class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int maxx = n;
        int minn = 0;
        vector<int> ans(n+1);
        for(int i=n;i>0;--i){
            if(s[i-1] == 'D'){
                ans[i] = (minn++);
            }else{
                ans[i] = (maxx--);
            }
        }
        ans[0] = minn;
        return ans;
    }
};