class Solution {
public:
    vector<string> ans;
    void backtrack(string s, int sum, int n){
        if(sum < 0){
            return;
        }
        if(s.size() == (n<<1)){
            if(sum == 0){
                ans.push_back(s);
            }
            return;
        }
        backtrack(s+'(', sum+1, n);
        backtrack(s+')', sum-1, n);
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int sum = 0;
        backtrack(s, sum, n);
        return ans;
    }
};