class Solution {
public:
    bool isPrime(int n) {
        int x = sqrt(n);
        for (int i = 2; i <= x; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto& x : nums) {
            int n = sqrt(x);
            int hasDivisor = false;
            int d;
            for (int i = 2; i <= n; ++i) {
                if (x % i == 0) {
                    hasDivisor = true;
                    d = i;
                    break;
                }
            }
            if (!hasDivisor) {
                continue;
            }
            if ((d * d * d) == x || ((d * d != x) && isPrime(x / d))) {
                ans += (1 + d + (x / d) + x);
            }
        }

        return ans;
    }
};