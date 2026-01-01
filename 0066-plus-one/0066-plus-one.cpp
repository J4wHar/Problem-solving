class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for (int i=n-1;i>=0;--i){
            digits[i] += carry;
            if (digits[i] < 10){
                carry = 0;
            } else {
                digits[i] %= 10;
                carry = 1;
            }
        }
        if (carry == 0){
            return digits;
        } else {
            vector<int> ans;
            ans.push_back(1);
            for (auto& x : digits){
                ans.push_back(x);
            }
            return ans;
        }

        return {};
    }
};