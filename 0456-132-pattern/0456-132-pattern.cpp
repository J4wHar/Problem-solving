class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> left, right;
        int n = nums.size();
        for(int i=1;i<n;++i){
            ++right[nums[i]];
        }
        for(int i=1;i<n-1;++i){
            ++left[nums[i-1]];
            --right[nums[i]];
            if(!right[nums[i]]){
                right.erase(nums[i]);
            }
            int l = left.begin()->first;
            auto it = right.upper_bound(l);
            if(it == right.end()){
                continue;
            }
            int m = nums[i];
            int r = it->first;
            if(l<m && r<m){
                return true;
            }
        }
        return false;
    }
};