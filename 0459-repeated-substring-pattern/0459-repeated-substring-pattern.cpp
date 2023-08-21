class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string sub = "";
        for(int i=0;i<n/2;++i){
            sub += s[i];
            if(n%(sub.size()) == 0){
                int d = n/(sub.size());
                string appended = "";
                while(d--){
                    appended += sub;
                }
                if(appended == s){
                    return true;
                }
            }
            
        }
        return false;
    }
};