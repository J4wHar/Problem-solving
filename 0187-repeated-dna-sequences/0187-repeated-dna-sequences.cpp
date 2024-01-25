class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> occ;
        vector<string> ans;
        int n = s.size();
        for(int i=0;i<=n-10;++i){
            string subString = s.substr(i, 10);
            ++occ[subString];
        }
        for(auto& x: occ){
            if(x.second > 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};