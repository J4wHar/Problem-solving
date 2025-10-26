class Solution {
public:
int findMaxLength(vector<int>& nums) {
    int sum = 0;
    unordered_map<int, int> minIndex;
    unordered_map<int, int> maxIndex;
    int n = nums.size();
    int pref[n+1];
    pref[0] = 0;
    for (int i=1;i<=n;++i){
        pref[i] = pref[i-1] + (nums[i-1]==1 ? 1 : -1);
    }
    for (int i=0;i<=n;++i){
        maxIndex[pref[i]] = max(maxIndex[pref[i]], i);
        if (!minIndex.count(pref[i])){
            minIndex[pref[i]] = i;
        }else{
            minIndex[pref[i]] = min(minIndex[pref[i]], i);
        }
    }
    int ans = 0;
    for (auto& x: maxIndex){
        ans = max(ans, x.second-minIndex[x.first]);
    }

    return ans;
}
};