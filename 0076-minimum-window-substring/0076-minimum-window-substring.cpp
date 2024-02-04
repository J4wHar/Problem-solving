class Solution {
public:
    bool valid(unordered_map<char, int>& s, unordered_map<char, int>& t){
        for(auto &x: t){
            if(x.second > s[x.first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l = 0;
        int n = s.size();
        unordered_map<char, int> occS, occT;
        int sz = 1e9;
        int b = 0;
        bool cond = false;
        for(auto& x: t){
            ++occT[x];
        }
        for(int r=0;r<n;++r){
            ++occS[s[r]];
            while(valid(occS, occT) && l<=r){
                cond = true;
                if(sz > r-l+1){
                    sz = r-l+1;
                    b = l;
                }
                --occS[s[l++]];
            }
        }
        if(cond){
            return s.substr(b, sz);
        }
        return "";
    }
};