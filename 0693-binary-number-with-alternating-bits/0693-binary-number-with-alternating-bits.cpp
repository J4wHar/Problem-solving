class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool isZero = !(n & 1);
        while (n) {
            n = n >> 1;
            if ((n & 1) && isZero) {
                isZero = false;
            } else if (!isZero & !(n & 1)) {
                isZero = true;
            } else {
                return false;
            }
        }

        return true;
    }
};