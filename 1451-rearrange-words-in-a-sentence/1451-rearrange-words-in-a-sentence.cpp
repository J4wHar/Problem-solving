class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> mp;
        string ans = "";
        string cur = "";
        text[0] = tolower(text[0]);
        for(auto x:text){
            if(x == ' '){
                mp[cur.size()].push_back(cur);
                cur = "";
            }else{
                cur += x;
            }
        }
        if(!cur.empty()){
            mp[cur.size()].push_back(cur);
        }
        for(auto x:mp){
            for(auto str:x.second){
                ans += str + ' ';
            }
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};