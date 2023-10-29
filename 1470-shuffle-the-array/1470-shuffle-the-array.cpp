class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n<<1);
        int idx = 0;
        for(int i=0;i<(n<<1);i+=2){
            ans[i] = nums[idx++];
        }
        idx = n;
        for(int i=1;i<(n<<1);i+=2){
            ans[i] = nums[idx++];
        }
        return ans;
    }
};