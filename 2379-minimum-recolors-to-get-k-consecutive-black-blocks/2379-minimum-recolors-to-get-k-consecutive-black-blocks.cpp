class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int cnt = 0;
        int ans = k;
        for(int i=0;i<n;++i){
            if(i<k){
                cnt += blocks[i]=='B';
                ans = min(ans, k-cnt);
            }else{
                cnt += blocks[i]=='B';
                cnt -= blocks[i-k]=='B';
                ans = min(ans, k-cnt);
            }
        }
        return ans;
    }
};