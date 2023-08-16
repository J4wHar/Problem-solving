class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        map<int, int> window;
        for(int i=0;i<n;++i){
            if(i<k){
                ++window[nums[i]];
                if(i==k-1){
                    auto it = window.end();
                    --it;
                    ans.push_back(it->first);
                }
            }else{
                --window[nums[i-k]];
                auto it = window.find(nums[i-k]);
                if(it->second == 0){
                    window.erase(nums[i-k]);
                }
                ++window[nums[i]];
                it = window.end();
                --it;
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};