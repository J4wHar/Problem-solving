class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        int curSum = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i];
            curSum += x;
            sum -= x;
            if ((curSum - sum) % 2 == 0) {
                ++ans;
            }
        }

        return ans;
    }
};