class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,int>> d;
        long long sum=0 ; 
        int ans=1e9;
        int n=nums.size();
        for(int i=0;i<n;++i){
            sum += nums[i];
            if (sum >= k){
                ans = min(ans , i+1);
            }
            if(d.empty() || d.back().first < sum){
                d.push_back(make_pair(sum , i));
            }else{
                while(!d.empty() && sum <= d.back().first){
                    d.pop_back();
                }
                d.push_back(make_pair(sum , i));
            }
            while(d.back().first - d.front().first >= k){
                ans = min(ans , d.back().second - d.front().second);
                d.pop_front();
            }
        }
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};