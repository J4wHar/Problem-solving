class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int, int> occ;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;++i){
            ++occ[nums[i]];
        }
        int ans = 0;
        vector<int> pref;
        for(int i=0;i<n;++i){
            auto it = occ.upper_bound(nums[i]);
            if(it == occ.end()){
                pref.push_back(-1);
            }else{
                pref.push_back(it->first);
                --(it->second);
                if(!it->second){
                    occ.erase(it);
                }
            }
            ans += pref.back() > 0;
        }
        return ans;
    }
};