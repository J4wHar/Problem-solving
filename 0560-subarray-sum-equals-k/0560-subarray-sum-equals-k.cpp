class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int pref[n+1];
        pref[0] = 0;
        map<int,int> occ_pref;
        ++occ_pref[0];
        for(int i=1;i<=n;++i){
            pref[i] = pref[i-1] + nums[i-1];
            ++occ_pref[pref[i]];
        }
        for(int i=n;i>0;--i){
            --occ_pref[pref[i]];
            ans += occ_pref[pref[i]-k];
        }
        return ans;
    }
};