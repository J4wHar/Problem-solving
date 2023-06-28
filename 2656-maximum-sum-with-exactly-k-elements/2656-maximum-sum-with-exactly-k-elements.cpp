class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            m = max(m , nums[i]);
        }
        return m*k + ((k*(k-1))>>1) ;
    }
};