class Solution {
public:
bool canEatAllBananas(vector<int>& piles, int m, int h){
    for (auto& x : piles){
        if (x%m == 0){
            h -= (x/m);
        }else{
            h -= ((x/m)+1);
        }
        if (h < 0){
            return false;
        }
    }
    
    return true;
}
int minEatingSpeed(vector<int>& piles, int h) {
    long long l=1;
    long long r=1e9;
    long long m;
    long long ans = 1e9;
    while (l<=r){
        m = l+(r-l)/2;
        if (canEatAllBananas(piles, m, h)){
            r = m-1;
            ans = min(ans, m);
        }else{
            l = m+1;
        }
    }
    
    return ans;
}
};