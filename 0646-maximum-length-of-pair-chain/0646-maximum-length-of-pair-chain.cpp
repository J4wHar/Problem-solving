class Solution {
public:
    int memo[1000][2010];
    int n;
    int solve(int i, int cur, vector<vector<int>>& pairs){
        if(i == n){
            return 0;
        }
        if(memo[i][cur] != -1){
            return memo[i][cur];
        }
        if(cur < pairs[i][0]+1001){
            return memo[i][cur] = max(1+solve(i+1, pairs[i][1]+1001, pairs), 
                                     solve(i+1, cur, pairs));
        }
        return memo[i][cur] = solve(i+1, cur, pairs);
    }
    static bool compare(vector<int>& v1, vector<int>& v2){
        if(v1[1] == v2[1]){
            return v1[0] < v2[0];
        }
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(memo, -1, sizeof memo);
        sort(pairs.begin(), pairs.end(), compare);
        return solve(0, 0, pairs);
    }
};