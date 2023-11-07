class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> req;
        int n = dist.size();
        int cnt = 0;
        for(int i=0;i<n;++i){
            if(speed[i] >= dist[i]){
                req.push_back(0);
            }else{
                if(dist[i]%speed[i] == 0){
                    req.push_back(dist[i]/speed[i]);
                }else{
                    req.push_back((dist[i]/speed[i])+1);
                }
            }
        }
        sort(req.begin(), req.end());
        for(int i=0;i<n;++i){
            if(i == 0){
                ++cnt;
            }
            else if(req[i] - cnt > 0){
                ++cnt;
            }else{
                return cnt;
            }
        }
        return cnt;
    }
};