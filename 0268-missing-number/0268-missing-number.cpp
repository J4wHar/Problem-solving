class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bitset<10001> exists = 0;
        for(int i=0;i<n;++i){
            exists[nums[i]] = 1;
        }
        for(int i=0;i<=n;++i){
            if(!exists[i]){
                return i;
            }
        }
        return 0;
    }
};