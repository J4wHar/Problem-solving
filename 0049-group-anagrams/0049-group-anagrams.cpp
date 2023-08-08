class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto x: strs){
            string s = x;
            sort(s.begin(), s.end());
            mp[s].push_back(x);
        }
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};