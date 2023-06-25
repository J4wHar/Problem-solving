class Solution {
public:
    int n;
    int memo[100][201];
    int MOD = 7 + 1e9;
    int solve(int current , int fuel , int finish , vector<int>& locations){
        if(fuel == 0){
            return current==finish ? 1 : 0;
        }
        if(fuel < 0){
            return 0;
        }
        if(memo[current][fuel] != -1){
            return memo[current][fuel];
        }
        memo[current][fuel] = current == finish;
        for(int x=0;x<n;++x){
            if(x != current && fuel) 
                memo[current][fuel] = (memo[current][fuel]%MOD) + solve(x,fuel-abs(locations[x]-locations[current]),finish,locations);
            memo[current][fuel] %= MOD;
        }
        return memo[current][fuel];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(memo , -1 , sizeof memo);
        return solve(start , fuel , finish , locations);
    }
};