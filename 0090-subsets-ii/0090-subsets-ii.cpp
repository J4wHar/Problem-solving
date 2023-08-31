class Solution {
public:
    set<vector<int>> ans;
    void backtrack(int idx, vector<int>& temp, bitset<10> visited, vector<int>& nums){
        ans.insert(temp);
        for(int i=idx;i<nums.size();++i){
            if(!visited[i]){
                visited[i] = 1;
                temp.push_back(nums[i]);
                backtrack(i+1, temp, visited, nums);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        bitset<10> visited;
        sort(nums.begin(), nums.end());
        backtrack(0, temp, visited, nums);
        vector<vector<int>> res;
        for(auto x: ans){
            res.push_back(x);
        }
        return res;
    }
};