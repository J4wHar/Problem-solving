class Solution {
public:
    static bool compare(pair<int, bool> p1, pair<int, bool> p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, bool>> v;
        int n = intervals.size();
        for(int i=0;i<n;++i){
            v.push_back(make_pair(intervals[i][0], true));
            v.push_back(make_pair(intervals[i][1], false));
        }
        sort(v.begin(), v.end(), compare);
        int cur = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<(n<<1);++i){
            pair<int, bool> p = v[i];
            if(p.second){
                if(cur == 0){
                    temp.push_back(p.first);
                }
                ++cur;
            }else{
                --cur;
                if(cur == 0){
                    temp.push_back(p.first);
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};