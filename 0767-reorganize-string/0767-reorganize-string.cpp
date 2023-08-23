class Solution {
public:
    static bool compare(pair<char, int> x, pair<char, int> y){
        return x.second > y.second;
    }
    string reorganizeString(string s) {
        int n = s.size();
        map<char, int> occ;
        for(int i=0;i<n;++i){
            ++occ[s[i]];
        }
        deque<pair<char, int>> v;
        for(auto x: occ){
            v.push_back(x);
        }
        sort(v.begin(), v.end(), compare);
        int index = v.size()-1;
        char ans[n];
        for(int i=0;i<n;++i){
            if(i&1){
                ans[i] = v[index].first;
                --v[index].second;
                if(!v[index].second){
                    --index;
                }
            }
        }
        for(int i=0;i<n;++i){
            if(!(i&1)){
                ans[i] = v[index].first;
                --v[index].second;
                if(!v[index].second){
                    --index;
                }
            }
        }
        string res = "";
        for(int i=0;i<n;++i){
            res += ans[i];
        }
        for(int i=1;i<n;++i){
            if(res[i] == res[i-1]){
                return "";
            }
        }
        return res;
    }
};