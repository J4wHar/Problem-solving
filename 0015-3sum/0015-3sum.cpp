class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;++i){
            int l = i+1;
            int r = n-1;
            while(l < r){
                int x = nums[i] + nums[l] + nums[r];
                if(x > 0){
                    --r;
                }else if(x < 0){
                    ++l;
                }else{
                    res.insert({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                }
            }
        }
        for(auto x: res){
            ans.push_back(x);
        }
        return ans;
    }
};