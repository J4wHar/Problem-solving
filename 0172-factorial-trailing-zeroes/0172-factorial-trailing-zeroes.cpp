class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2=0 , cnt5=0;
        int cur;
        for(int x=2;x<=n;++x){
            cur = x;
            while(!(cur&1)){
                cur = (cur>>1);
                ++cnt2;
            }
            while(cur%5 == 0){
                cur /= 5;
                ++cnt5;
            }
        }
        return min(cnt2 , cnt5);
    }
};