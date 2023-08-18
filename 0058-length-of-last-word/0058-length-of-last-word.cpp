class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans = "";
        int n = s.size();
        bool endsWithSpace = s[n-1] == ' ';
        if(!endsWithSpace){
            int sz = 0;
            for(int i=n-1;i>=0;--i){
                if(s[i] == ' '){
                    return sz;
                }
                ++sz;
            }
            return sz;
        }else{
            int index;
            int sz = 0;
            for(int i=n-1;i>=0;--i){
                if(s[i] != ' '){
                    index = i;
                    break;
                }
            }
            for(int i=index;i>=0;--i){
                if(s[i] == ' '){
                    return sz;
                }
                ++sz;
            }
            return sz;
        }
        return 0;        
    }
};