class Solution {
public:
    int findMin(vector<int>& nums, int l = 0, int r = -1) {
        cout << l << " " << r << endl;
        if (r == -1) {
            r = nums.size() - 1;
        }
        if (l == r) {
            return nums[l];
        }
        if (r == l + 1) {
            return min(nums[l], nums[r]);
        }
        if (r == l + 2) {
            return min(min(nums[l], nums[l + 1]), nums[r]);
        }
        int m = l + ((r - l) / 2);
        if (nums[l] < nums[m] && nums[m] < nums[r]) {
            return findMin(nums, l, m - 1);
        }
        if (nums[m] > nums[r]) {
            return findMin(nums, m, r);
        }

        return findMin(nums, l, m);
    }
};