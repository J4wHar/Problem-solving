class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_map<int, deque<int>> idx;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            idx[temperatures[i]].push_back(i);
        }
        for(int i=0;i<n;++i){
            ans[i] = 1e7;
            idx[temperatures[i]].pop_front();
            for(int temp=temperatures[i]+1;temp<101;++temp){
                if(!idx[temp].empty()){
                    ans[i] = min(ans[i], idx[temp][0] - i);
                }
            }
            if(ans[i] == 1e7){
                ans[i] = 0;
            }
        }
        return ans;
    }
};