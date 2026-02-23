class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ss;
        int n = s.size();
        for (int i=0;i<n-k+1;++i){
            string cur = s.substr(i, k);
            ss.insert(cur);
        }

        return ss.size() == 1<<k;
    }
};