class Solution {
public:
    int bs(int arr[], int l, int r, int target){
        int m = l+(r-l)/2;
        if(r<l){
            return 1e7;
        }
        if(arr[m] == target){
            return m;
        }
        if(arr[m] < target){
            return bs(arr, m+1, r, target);
        }
        return bs(arr, l, m-1, target);
    }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int pref[n+1], suff[n+1];
        pref[0] = 0;
        suff[0] = 0;
        int ans = 1e7;
        for(int i=1;i<=n;++i){
            pref[i] = pref[i-1] + nums[i-1];
            suff[i] = suff[i-1] + nums[n-i];
        }
        for(int i=0;i<=n;++i){
            int cur = i+bs(suff, 0, n, x-pref[i]);
            if(cur <= n){
                ans = min(ans, cur);
            }
        }
        if(ans == 1e7){
            return -1;
        }
        return ans;
    }
};