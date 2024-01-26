class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        for(auto& x: nums){
            cnt0 += x==0;
            cnt1 += x==1;
        }
        int cnt2 = nums.size() - cnt1 - cnt0;
        int cur = 0;
        while(cnt0--){
            nums[cur++] = 0;
        }
        while(cnt1--){
            nums[cur++] = 1;
        }
        while(cnt2--){
            nums[cur++] = 2;
        }
    }
};