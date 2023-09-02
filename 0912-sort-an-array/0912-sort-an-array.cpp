class Solution {
public:
    void mrg(int l, int md, int r, vector<int>& nums){
        vector<int> ans;
        int i=l, j=md+1;
        while(i<=md && j<=r){
            if(nums[i] < nums[j]){
                ans.push_back(nums[i++]);
            }else{
                ans.push_back(nums[j++]);
            }
        }
        while(i<=md){
            ans.push_back(nums[i++]);
        }
        while(j<=r){
            ans.push_back(nums[j++]);
        }
        int idx = 0;
        for(int i=l;i<=r;++i){
            nums[i] = ans[idx++];
        }
    }
    
    void sort(int l, int r, vector<int>& nums){
        if(l == r){
            return;
        }
        int m = l+(r-l)/2;
        sort(l, m, nums);
        sort(m+1, r, nums);
        mrg(l, m, r, nums);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        sort(0, nums.size()-1, nums);
        return nums;
    }
};