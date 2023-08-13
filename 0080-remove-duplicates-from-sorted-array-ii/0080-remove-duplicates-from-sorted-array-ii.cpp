class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> occ;
        int n = nums.size();
        for(int i=0;i<n;++i){
            occ[nums[i]] = min(2, occ[nums[i]]+1);
        }
        vector<int> ans;
        for(auto x: occ){
            for(int i=0;i<x.second;++i){
                ans.push_back(x.first);
            }
        }
        nums = ans;
        return nums.size();
    }
};