class Solution {
public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        map<int, int> occ;
        vector<vector<int>> ans;
        for(auto &x: nums){
            ++occ[x];
            occ[x] = min(occ[x], 4);
        }
        nums.clear();
        for(auto &x: occ){
            for(int i=0;i<x.second;++i){
                nums.push_back(x.first);
            }
        }
        int n = nums.size();
        for(int i=0;i<n-3;i+=occ[nums[i]]){
            for(int j=i+1;j<n-2;j+=max(1, occ[nums[j]]-(nums[i]==nums[j]))){
                int s = nums[i] + nums[j];
                int l = j+1;
                int r = n-1;
                while(l < r){
                    long long sum = (long long) s + nums[l] + nums[r];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        r -= occ[nums[r]];
                    }else if(sum < target){
                        ++l;
                    }else{
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};