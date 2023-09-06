class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int n=nums.size();
        if(n <= k+1){
            for(int i=0;i<n;++i){
                ++mp[nums[i]];
            }
            return mp.size() < n;
        }
        for(int i=0;i<n;++i){
            if(i<=k){
                ++mp[nums[i]];
                if(i == k){
                    if(mp.size()<=k){
                        return true;
                    }
                }
            }else{
                --mp[nums[i-k-1]];
                ++mp[nums[i]];
                if(!mp[nums[i-k-1]]){
                    mp.erase(nums[i-k-1]);
                }               
                if(mp.size()<=k){
                    return true;
                }
            }
        }
        return false;
    }
};