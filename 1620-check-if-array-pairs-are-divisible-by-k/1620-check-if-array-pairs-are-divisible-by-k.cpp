class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> occ;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            arr[i] %= k;
            if (arr[i] < 0) {
                arr[i] += k;
            }
            ++occ[arr[i]];
        }
        for (auto& x : occ) {
            if (x.first == 0) {
                if (x.second % 2) {
                    return false;
                }
                continue;
            }
            if (x.second != occ[k - x.first]) {
                return false;
            }
        }

        return true;
    }
};