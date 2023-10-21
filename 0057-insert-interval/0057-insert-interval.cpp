class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int, bool>> v;
        for(auto x: intervals){
            v.push_back(make_pair(x[0], false));
            v.push_back(make_pair(x[1], true));
        }
        v.push_back(make_pair(newInterval[0], false));
        v.push_back(make_pair(newInterval[1], true));
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int res = 0;
        vector<int> cur;
        for(auto &x: v){
            if(!x.second){
                if(res == 0){
                    cur.push_back(x.first);
                }
                ++res;
            }else{
                --res;
                if(res == 0){
                    cur.push_back(x.first);
                    ans.push_back(cur);
                    cur.clear();
                }
            }
        }
        return ans;
    }
};