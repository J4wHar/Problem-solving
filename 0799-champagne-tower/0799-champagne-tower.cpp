class Solution {
public:
    double min(double x, double y){
        if(x < y){
            return x;
        }
        return y;
    }
    double max(double x, double y){
        if(x < y){
            return y;
        }
        return x;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0){
            return 0.0;
        }
        double dp[100+1][100+1];
        dp[0][0] = poured;
        for(int i=1;i<=query_row;++i){
            for(int j=1;j<i;++j){
                double l = max(0, (double) (dp[i-1][j-1]-1)/2);
                double r = max(0, (double) (dp[i-1][j]-1)/2);
                dp[i][j] = l+r;
            }
            dp[i][0] = max(0, (double) (dp[i-1][0]-1)/2);
            dp[i][i] = dp[i][0];
        }
        for(int i=1;i<=query_row;++i){
            for(int j=0;j<=i;++j){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return min(dp[query_row][query_glass], 1);
    }
};