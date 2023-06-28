class Solution {
public:
    int minCostToMoveChips(vector<int>& nums) {
        int n = nums.size();
        int odd=0 , even=0;
        for(int i=0;i<n;++i){
            if(nums[i]&1){
                ++odd;
            }else{
                ++even;
            }
        }
        return min(odd , even);
    }
};