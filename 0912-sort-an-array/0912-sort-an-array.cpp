class Solution {
public:
    
    vector<int> mrg(vector<int> left, vector<int> right){
        vector<int> ans;
        int l=0, r=0, n=left.size(), m=right.size();
        while(l<n && r<m){
            if(left[l] < right[r]){
                ans.push_back(left[l++]);
            }else{
                ans.push_back(right[r++]);
            }
        }
        while(l<n){
            ans.push_back(left[l++]);
        }
        while(r<m){
            ans.push_back(right[r++]);
        }
        return ans;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums;
        }
        vector<int> left, right;
        int n = nums.size();
        for(int i=0;i<(n>>1);++i){
            left.push_back(nums[i]);
        }
        for(int i=(n>>1);i<n;++i){
            right.push_back(nums[i]);
        }
        return mrg(sortArray(left), sortArray(right));
    }
};