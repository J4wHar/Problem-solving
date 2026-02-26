class Solution {
public:
    string increment(string s){
        int n = s.size();
        for (int i=n-1;i>=0;--i){
            if (s[i] == '1'){
                s[i] = '0';
                continue;
            }
            if (s[i] == '0'){
                s[i] = '1';
                return s;
            }
        }
        return '1' + s;
    }
    int numSteps(string s) {
        if (s == "1"){
            return 0;
        }
        if (s.back() == '0'){
            s.pop_back();
            return 1 + numSteps(s);
        }
        s = increment(s);
        return 1 + numSteps(s);
    }
};