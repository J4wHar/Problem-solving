class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        reverse(digits.begin() , digits.end());
        for(int i=0;i<n;++i){
            if(carry){
                if(digits[i] == 9){
                    digits[i] = 0;
                }else{
                    ++digits[i];
                    carry = 0;
                }
            }
        }
        if(carry){
            digits.push_back(1);
        }
        reverse(digits.begin() , digits.end());
        return digits;
    }
};