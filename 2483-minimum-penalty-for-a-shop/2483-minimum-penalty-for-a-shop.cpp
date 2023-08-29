class Solution {
public:
    int bestClosingTime(string customers) {
        int cnt = 0;
        int n = customers.size();
        int pref[n+1];
        pref[0] = 0;
        for(int i=1;i<=n;++i){
            if(customers[i-1] == 'Y'){
                pref[i] = pref[i-1] + 1;
            }else{
                pref[i] = pref[i-1] - 1;
            }
            cnt = max(cnt, pref[i]);
        }
        for(int i=0;i<=n;++i){
            if(pref[i] == cnt){
                return i;
            }
        }
        return 0;
    }
};