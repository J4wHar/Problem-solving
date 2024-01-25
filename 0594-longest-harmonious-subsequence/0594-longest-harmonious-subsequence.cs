public class Solution {
    public int FindLHS(int[] nums) {
        int n = nums.Length;
        int l = 0;
        int ans = 0;
        Array.Sort(nums);
        for(int r=0;r<n;r++)
        {
            while(nums[r]-nums[l]>1 && l<r)
            {
                l++;
            }
            if(nums[r]-nums[l] == 1)
            {
                ans = Math.Max(ans, r - l + 1);
            }
        }
        return ans;
    }
}