class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int l = 0;
        sort(nums.begin(), nums.end());
        for(int r=0;r<n;++r){
            while(nums[r]-nums[l]>1 && l<r){
                ++l;
            }
            if(nums[r]-nums[l] == 1){
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};