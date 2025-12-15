class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        stack<int> st;
        for (auto& x : prices){
            if (st.empty()){
                st.push(x);
                continue;
            }
            if (x == st.top() - 1){
                st.push(x);
            } else{
                ans += ((st.size() * (st.size()+1))/2);
                st = stack<int>();
                st.push(x);
            }
        }
        ans += ((st.size() * (st.size()+1))/2);

        return ans;
    }
};