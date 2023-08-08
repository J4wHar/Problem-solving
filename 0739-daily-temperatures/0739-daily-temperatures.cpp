class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_map<int, vector<int>> idx;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            idx[temperatures[i]].push_back(i);
        }
        for(int i=0;i<n;++i){
            ans[i] = 1e7;
            for(int temp=temperatures[i]+1;temp<101;++temp){
                auto it = upper_bound(idx[temp].begin(), idx[temp].end(), i);
                if(it != idx[temp].end()){
                    ans[i] = min(ans[i], *it - i);
                }
            }
            if(ans[i] == 1e7){
                ans[i] = 0;
            }
        }
        return ans;
    }
};