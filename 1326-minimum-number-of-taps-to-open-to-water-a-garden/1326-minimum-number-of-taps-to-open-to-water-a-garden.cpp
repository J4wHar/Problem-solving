class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int farthest[n+1];
        for(int i=0;i<=n;++i){
            farthest[i] = i;
        }
        for(int i=0;i<=n;++i){
            farthest[max(0, i-ranges[i])] = min(i+ranges[i], n);
        }
        while(r < n){
            int cur = 0;
            
            for(int i=l;i<=r;++i){
                cur = max(cur, farthest[i]);
            }
            if(cur == r){
                return -1;
            }
            ++ans;
            l = r+1;
            r = cur;
        }
        return ans;
    }
};