class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> occ;
        for (auto& x : nums){
            if (occ[x]){
                return x;
            }
            ++occ[x];
        }

        return 0;
    }
};