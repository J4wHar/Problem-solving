class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd Algorithm Cycle detection
        
        int slow=0, slow1=0, fast=0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        do{
            slow = nums[slow];
            slow1 = nums[slow1];
        }while(slow != slow1);
        
        return slow;
        
    }
};