public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        int n = nums.Length;
        int[][] ans = new int[n/3][];
        int idx = 0;
        for(int i=0;i<n;i+=3)
        {
            int x = i/3;
            ans[x] = new int[3];
            for(int j=0;j<3;j++)
            {
                ans[x][j] = nums[idx];
                idx++;
            }
            if(ans[x][2]-ans[x][0] > k)
            {
                return new int[0][];
            }
        }
        return ans;
    }
}