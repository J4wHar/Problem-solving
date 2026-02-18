class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        stack<int> st;
        int curDiff;
        int ans = 0;
        for (int& x : nums) {
            if (st.empty()) {
                st.push(x);
                continue;
            }
            if (st.size() == 1) {
                curDiff = x - st.top();
                st.push(x);
            } else {
                if (curDiff == (x - st.top())) {
                    st.push(x);
                } else {
                    int sz = st.size();
                    ans += sz > 2 ? ((sz - 1) * (sz - 2)) >> 1 : 0;
                    int p = st.top();
                    st = stack<int>();
                    st.push(p);
                    st.push(x);
                    curDiff = x - p;
                }
            }
        }

        int sz = st.size();
        ans += sz > 2 ? ((sz - 1) * (sz - 2)) >> 1 : 0;

        return ans;
    }
};