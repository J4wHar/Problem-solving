class Solution {
public:
    void handleCur(string& cur, stack<string>& st){
        if (cur.empty()){
            return;
        }
        if (cur == "."){
            cur = "";
            return;
        }
        if (cur == ".."){
            if (!st.empty()){
                st.pop();
            }
            cur = "";
            return;
        }
        st.push(cur);
        cur = "";
    }
    string simplifyPath(string path) {
        stack<string> st;
        string cur = "";
        for (char c : path) {
            if (c == '/') {
                handleCur(cur, st);
                continue;
            }
            cur += c;
        }
        handleCur(cur, st);
        vector<string> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            ans.push_back("/");
            st.pop();
        }
        string simplifiedPath = "";
        for (int i = ans.size() - 1; i >= 0; --i) {
            simplifiedPath += ans[i];
        }

        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};