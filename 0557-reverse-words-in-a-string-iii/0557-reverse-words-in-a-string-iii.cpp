class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;++i){
            if(s[i] == ' '){
                reverse(word.begin(), word.end());
                ans += word + " ";
                word = "";
            }else{
                word += s[i];
            }
        }
        reverse(word.begin(), word.end());
        return ans + word;
    }
};