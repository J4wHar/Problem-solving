class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int tot = n+m;
        int i1 = 0;
        int i2 = 0;
        vector<int> nums(tot);
        for(int i=0;i<tot;++i){
            if(i1<n && i2<m){
                if(nums1[i1] < nums2[i2]){
                    nums[i] = nums1[i1++];
                }else{
                    nums[i] = nums2[i2++];
                }
            }else if(i1<n){
                nums[i] = nums1[i1++];
            }else{
                nums[i] = nums2[i2++];
            }
        }
        if(tot&1){
            return nums[(tot>>1)];
        }else{
            return (double)(nums[tot>>1]+nums[(tot>>1)-1])/2;
        }
    }
};