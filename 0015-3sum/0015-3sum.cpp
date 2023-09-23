class Solution {
public:
    bool bs(int l, int r, int target, vector<int>& arr){
        int m = l+(r-l)/2;
        if(r<l){
            return false;
        }
        if(arr[m] == target){
            return true;
        }
        if(arr[m] < target){
            return bs(m+1, r, target, arr);
        }
        return bs(l, m-1, target, arr);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n-1;++j){
                if(bs(j+1, n-1, -nums[i]-nums[j], nums)){
                    res.insert({nums[i], nums[j], -nums[i]-nums[j]});
                }
            }
        }
        for(auto x: res){
            ans.push_back(x);
        }
        return ans;
    }
};