class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n+1];
        for(int i=0;i<=n;++i){
            int res = 0;
            int x = i;
            while(x > 0){
                if(x%2 == 1){
                    ++res;
                }
                x /= 2;
            }
            ans[i] = res;
        }
        return ans;
    }
}