class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cur = 1;
        int sz = 1;
        unordered_set<int> occ;
        while (cur % k) {
            cur = ((cur * 10) + 1) % k;
            if (occ.count(cur)){
                return -1;
            }

            occ.insert(cur);
            sz++;
        }

        return sz;
    }
};