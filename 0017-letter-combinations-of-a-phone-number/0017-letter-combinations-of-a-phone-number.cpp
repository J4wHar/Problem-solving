class Solution {
public:
    vector<string> ans;
    map<int,vector<char>> mp;
    void backtrack(int index , string& temp , string& digits){
        if(temp.size() == digits.size() && !temp.empty()){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<digits.size();++i){
            for(auto x : mp[digits[i]-'0']){
                temp += x;
                backtrack(i+1,temp,digits);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};
        string s;
        backtrack(0,s,digits);
        return ans;
    }
};