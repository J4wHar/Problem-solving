class Solution {
public:
    
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    stack<int> s;
    unordered_map<int, int> next;
    for (auto& x : nums2){
        if (s.empty() || s.top() > x){
            s.push(x);
        }else{
            while (!s.empty() && s.top() < x){
                next[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
    }
    while (!s.empty()){
        next[s.top()] = -1;
        s.pop();
    }
    for (auto& x : nums1){
        ans.push_back(next[x]);
    }

    return ans;
}

};