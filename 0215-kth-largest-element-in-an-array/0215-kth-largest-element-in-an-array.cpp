class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(heap.size() < n-k+1){
                heap.push(nums[i]);
            }else{
                if(nums[i] < heap.top()){
                    heap.push(nums[i]);
                    heap.pop();
                }
            }
        }
        return heap.top();
    }
};