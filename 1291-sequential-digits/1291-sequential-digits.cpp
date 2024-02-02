class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);
        int low_sz = l.size();
        int high_sz = h.size();
        vector<int> ans;
        for(int sz=low_sz;sz<=high_sz;++sz){
            for(int i=0;i<=9-sz;++i){
                string cur = s.substr(i, sz);
                int x = stoi(cur);
                if(x>=low && x<=high){
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};