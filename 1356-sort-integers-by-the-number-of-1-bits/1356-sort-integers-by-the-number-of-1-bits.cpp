class Solution {
public:
    // This is only a declaration, not a definition.
    // The compiler needs actual storage allocated somewhere → that's what inline does:
    inline static unordered_map<int, int> cnt;
    static bool compare(int x, int y){
        if (cnt[x] == cnt[y]){
            return x < y;
        }

        return cnt[x] < cnt[y];
    }
    void prepareCnt(vector<int>& arr){
        for (int x : arr){
            if (cnt.count(x)){
                continue;
            }
            int ans = 0;
            int cur = x;
            while (cur){
                ans += (cur & 1);
                cur = cur >> 1;
            }
            cnt[x] = ans;
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        prepareCnt(arr);
        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};