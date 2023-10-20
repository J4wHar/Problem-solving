class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;
        for(auto x: s){
            if(x == '#'){
                if(!ss.empty()){
                    ss.pop();
                }
            }else{
                ss.push(x);
            }
        }
        for(auto x: t){
            if(x == '#'){
                if(!tt.empty()){
                    tt.pop();
                }
            }else{
                tt.push(x);
            }
        }
        if(ss.size() != tt.size()){
            return false;
        }
        while(!ss.empty()){
            if(ss.top() != tt.top()){
                return false;
            }
            ss.pop();
            tt.pop();
        }
        return true;
    }
};