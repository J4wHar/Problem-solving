class Solution {
public:
    int ans = 0;
    vector<int> graph[100003];
    void dfs(int parent , int time , vector<int>& informTime){
        for(auto child : graph[parent]){
            dfs(child , time+informTime[child] , informTime);
        }
        ans = max(ans , time);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;++i){
            if(i != headID){
                graph[manager[i]].push_back(i);
            }
        }
        dfs(headID , informTime[headID] ,informTime);
        return ans;
    }
};