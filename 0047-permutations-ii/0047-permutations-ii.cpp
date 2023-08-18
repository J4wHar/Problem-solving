class Solution {
public:
    set<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& temp, bitset<8> visited){
        if(temp.size() == nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!visited[i]){
                visited[i] = 1;
                temp.push_back(nums[i]);
                backtrack(nums, temp, visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        bitset<8> visited = 0;
        vector<int> temp;
        backtrack(nums, temp, visited);
        for(auto x: ans){
            res.push_back(x);
        }
        return res;
    }
};