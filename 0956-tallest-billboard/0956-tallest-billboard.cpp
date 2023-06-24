class Solution {
public:
    int n;
    int memo[20][10000];
    int solve(int i , int diff , vector<int>& rods){
        if(i == n){
            if(diff == 0){
                return 0;
            }
            return -1e6;
        }
        if(memo[i][diff+5000] != -1){
            return memo[i][diff+5000];
        }
        return memo[i][diff+5000] = max(rods[i]+solve(i+1,diff+rods[i],rods),
                                               max(solve(i+1,diff-rods[i],rods),
                                                  solve(i+1,diff,rods)));
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        memset(memo , -1 , sizeof memo);
        int ans = solve(0,0,rods);
        return ans > 0 ? ans : 0 ;
    }
};