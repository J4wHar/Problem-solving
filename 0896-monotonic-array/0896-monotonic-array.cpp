class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool ordered = true;
        bool reversed = true;
        for(int i=1;i<n;++i){
            ordered &= nums[i-1] <= nums[i];
            reversed &= nums[i-1] >= nums[i];
        }
        return ordered | reversed;
    }
};