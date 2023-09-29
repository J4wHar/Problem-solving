class Solution {
public:
    string longestPalindrome(string s) {
        string o = "";
        string e = "";
        int n = s.size();
        for(int i=0;i<n;++i){
            int l = i-1;
            int r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                --l;
                ++r;
            }
            string cur = s.substr(l+1, r-l-1);
            if(o.size() < cur.size()){
                o = cur;
            }
        }
        for(int i=1;i<n;++i){
            if(s[i] == s[i-1]){
                int l = i-2;
                int r = i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    --l;
                    ++r;
                }
                string cur = s.substr(l+1, r-l-1);
                if(e.size() < cur.size()){
                    e = cur;
                }
            }
        }
        if(e.size() < o.size()){
            return o;
        }
        return e;        
    }
};