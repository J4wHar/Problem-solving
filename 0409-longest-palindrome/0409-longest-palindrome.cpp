class Solution {
public:
    static bool compare(pair<char, int> p1, pair<char, int> p2){
        return p1.second > p2.second;
    }
    int longestPalindrome(string s) {
        unordered_map<char, int> occ;
        vector<pair<char, int>> v;
        bool impAvailable = true;
        int ans = 0;
        for(auto &x: s){
            ++occ[x];
        }
        for(auto &x: occ){
            v.push_back(x);
        }
        sort(v.begin(), v.end(), compare);
        for(auto &x: v){
            if(x.second & 1){
                if(impAvailable){
                    ans += x.second;
                    impAvailable = false;
                }else{
                    ans += x.second - 1;
                }
            }else{
                ans += x.second;
            }
        }
        return ans;
    }
};