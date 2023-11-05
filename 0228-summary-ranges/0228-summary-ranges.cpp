class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()){
            return ans;
        }
        int n = nums.size();
        vector<int> cur;
        for(auto &x: nums){
            if(cur.empty()){
                cur.push_back(x);
            }else{
                int c = cur.back();
                if(x == c+1){
                    cur.push_back(x);
                }else{
                    string x1 = to_string(cur[0]);
                    string x2 = to_string(c);
                    if(x1 == x2){
                        ans.push_back(x1);
                    }else{
                        ans.push_back(x1 + "->" + x2);
                    }
                    cur.clear();
                    cur.push_back(x);
                }
            }
        }
        string x1 = to_string(cur[0]);
        string x2 = to_string(cur.back());
        if(x1 == x2){
            ans.push_back(x1);
        }else{
            ans.push_back(x1 + "->" + x2);
        }
        return ans;
    }
};