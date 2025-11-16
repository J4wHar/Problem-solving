class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int, int> occ;
        for (auto& x : arr1){
            ++occ[x];
        }
        for (auto& x : arr2){
            while (occ[x]){
                ans.push_back(x);
                occ[x]--;
            }
        }
        for (auto& x : occ){
            int cur = x.second;
            if (cur){
                while (cur){
                    ans.push_back(x.first);
                    cur--;
                }
            }
        }
        
        return ans;
    }
};