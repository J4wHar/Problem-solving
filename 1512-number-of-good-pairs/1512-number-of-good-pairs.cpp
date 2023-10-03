class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>occ;
        for(auto &x: nums){
            ++occ[x];
        }
        int ans = 0;
        for(auto &x :occ){
            ans += ((x.second*(x.second-1)))>>1;
        }
        return ans;
    }
};