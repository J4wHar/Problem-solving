class Solution {
public:
    int solve(string s){
        int ans = 0;
        int cur;
        for(auto x:s){
            cur = (int) x-'0';
            ans += (cur*cur);
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int> hist;
        string s = to_string(n);
        while(!hist.count(n)){
            hist.insert(n);
            n = solve(s);
            s = to_string(n);
        }
        return hist.count(1);
    }
};